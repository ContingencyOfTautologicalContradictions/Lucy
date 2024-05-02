export module Lucy.Meta.Underlying;
import Lucy.Meta.Enumeration;

export template<Enumeration EnumType> using Underlying = __underlying_type(EnumType);