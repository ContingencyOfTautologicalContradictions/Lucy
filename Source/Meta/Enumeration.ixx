export module Lucy.Meta.Enumeration;

export template<class EnumType> concept Enumeration = __is_enum(EnumType);

export template<class EnumType> concept NotEnumeration = not __is_enum(EnumType);