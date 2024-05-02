export module Lucy.Meta.TokenTree;
import Lucy.Core.Size;
import Lucy.Core.Abort;
import std;

consteval unsigned long long int Convert(const std::string& content, unsigned long long int base)
{
    unsigned long long int ret = 0ull, mul = 1ull;
    for(Size x = content.size() - 1z; x > 0z; --x)
    {
        const char character = content[x];
        ret += character >= 'a' and character <= 'f' ? (10 + (character - 'a')) * mul : character >= 'A' and character <= 'F' ? (10 + (character - 'A')) * mul : (character - '0') * mul;
        mul *= base;
    }
    const char character = content[0];
    return ret += character >= 'a' and character <= 'f' ? (10 + (character - 'a')) * mul : character >= 'A' and character <= 'F' ? (10 + (character - 'A')) * mul : (character - '0') * mul;
}

class Location
{
public:
    Size line, character;
};

class Range
{
public:
    Location start, end;
};

enum class PreprocessorToken : unsigned char
{
    LiteralString,
    LiteralCharacter,
    LiteralMultiCharacter,
    Division,

};

class PreprocessorWord
{
public:
    Range range;

    std::string content;

    PreprocessorToken token;
};

enum class Preprocessing : unsigned char
{
    General,
    String,
    Character,
    Bar,
    OctalDigit,
    NamedUniversalCharacter,
    PreComment,
    SingleComment,
    MultiComment,
    MultiEndComment,

};

export template<char... characters> class [[nodiscard]] TokenTree
{
public:
    consteval TokenTree(const Size indentation = 4z) noexcept
    {
        std::vector<PreprocessorWord> words;
        {
            PreprocessorWord word;
            std::string key;
            Location location, previous{};
            location.line = 1z;
            location.character = 0z;
            using enum Preprocessing;
            Preprocessing mode = General, last = General;
            unsigned char submode = 0u;
            constexpr Size multicharacter_size = sizeof(int), size = sizeof...(characters) + 1z;
            constexpr char vcharacters[size] = {characters..., '\n'};
            for(Size x = 0z; x < size; ++x)
            {
                previous = location;
                const char character = vcharacters[x];
                switch(character)
                {
                    default:
                        ++location.character;
                    break;
                    case '\r':
                        if(vcharacters[x + 1z] not_eq '\n')
                        {
                            ++location.line;
                            location.character = 0z;
                        }
                    break;
                    case '\n':
                        ++location.line;
                        location.character = 0z;
                    break;
                    case '\t':
                        location.character += indentation;
                }
                switch(mode)
                {
                    case General:
                        switch(character)
                        {
                            case '"':
                                word.range.start = location;
                                word.token = LiteralString;
                                mode = String;
                            break;
                            case '\'':
                                word.range.start = location;
                                word.token = LiteralCharacter;
                                mode = Character;
                            break;
                            case '/':
                                word.range.start = location;
                                word.token = Division;
                                mode = PreComment;
                        }
                    break;
                    case String:
                        switch(character)
                        {
                            default:
                                word.content.append(1z, character);
                            break;
                            case '"':
                                word.range.end = location;
                                words.push_back(word);
                                word.content.clear();
                                mode = General;
                            break;
                            case '\\':
                                last = String;
                                mode = Bar;
                        }
                    break;
                    case Character:
                        switch(character)
                        {
                            default:
                                word.content.append(1z, character);
                            break;
                            case '\'':
                                word.range.end = location;
                                if(word.content.size() > 1z)
                                {
                                    if(word.content.size() < multicharacter_size)
                                        mode = LiteralMultiCharacter;
                                    else
                                        Abort();
                                }
                                words.push_back(word);
                                word.content.clear();
                                mode = General;
                            break;
                            case '\\':
                                last = Character;
                                mode = Bar;
                            break;
                            case '\n':
                            case '\r':
                                Abort();
                        }
                    break;
                    case Bar:
                        switch(character)
                        {
                            default:
                                Abort();
                            case 'n':
                                word.content.append(1z, '\n');
                                mode = last;
                            break;
                            case 't':
                                word.content.append(1z, '\t');
                                mode = last;
                            break;
                            case 'v':
                                word.content.append(1z, '\v');
                                mode = last;
                            break;
                            case 'b':
                                word.content.append(1z, '\b');
                                mode = last;
                            break;
                            case 'r':
                                word.content.append(1z, '\r');
                                mode = last;
                            break;
                            case 'f':
                                word.content.append(1z, '\f');
                                mode = last;
                            break;
                            case 'a':
                                word.content.append(1z, '\a');
                                mode = last;
                            break;
                            case '\\':
                                word.content.append(1z, '\\');
                                mode = last;
                            break;
                            case '?':
                                word.content.append(1z, '?');
                                mode = last;
                            break;
                            case '\'':
                                word.content.append(1z, '\'');
                                mode = last;
                            break;
                            case '"':
                                word.content.append(1z, '"');
                                mode = last;
                            break;
                            case '0':
                            case '1':
                            case '2':
                            case '3':
                            case '4':
                            case '5':
                            case '6':
                            case '7':
                                key.append(1z, character);
                                mode = OctalDigit;
                            break;
                            case 'N':

                            break;
                        }
                    break;
                    case OctalDigit:
                        switch(character)
                        {
                            default:
                                const unsigned long long int value = Convert(key, 8ull);
                                if(value > 255ull)
                                    Abort();
                                key.clear();
                                word.content.append(1z, static_cast<char>(value));
                                location = previous;
                                --x;
                                mode = last;
                            break;
                            case '0':
                            case '1':
                            case '2':
                            case '3':
                            case '4':
                            case '5':
                            case '6':
                            case '7':
                                if(key.size() == 3z)
                                {
                                    const unsigned long long int value = Convert(key, 8ull);
                                    if(value > 255ull)
                                        Abort();
                                    key.clear();
                                    word.content.append(1z, static_cast<char>(value));
                                    location = previous;
                                    --x;
                                    mode = last;
                                }
                                else
                                    key.append(1z, character);
                        }
                    break;
                    case NamedUniversalCharacter:
                        if(submode)
                            switch(character)
                            {
                                default:
                                    key.append(1z, character);
                                break;
                                case '}':
                                    
                                break;
                                case '\n':
                                case '\r':
                                    Abort();
                            }
                        else if(character == '{')
                            submode = 1u;
                        else
                            Abort();
                    break;
                    case PreComment:
                        switch(character)
                        {
                            case ''
                        }
                    break;
                }
            }
        }
    }
};