#ifndef lucy_core_exception_exception
#define lucy_core_exception_exception
#define lucy_throwable(...) ([[maybe_unused]] ::Exception& exception_object_private_and_secret __VA_OPT__(,) __VA_ARGS__)
#define lucy_record if([[maybe_unused]] ::Exception exception_object_private_and_secret; exception_object_private_and_secret_stub)
#define lucy_try exception_object_private_and_secret = [&]
#define lucy_detect(...) (exception_object_private_and_secret __VA_OPT__(,) __VA_ARGS__)
#define lucy_throw exception_object_private_and_secret =
#define lucy_catch(first, ...) if(exception_object_private_and_secret.Thrown() and exception_object_private_and_secret.Catch(first __VA_OPT__(,) __VA_ARGS__))
#define lucy_any if(exception_object_private_and_secret.Any())
#define lucy_finally if(exception_object_private_and_secret.Finally())
#define lucy_recover(type) static_cast<type>(exception_object_private_and_secret)
#define lucy_anomaly(name) enum class [[nodiscard]] name : unsigned short
#define lucy_what exception_object_private_and_secret.Message()
#define lucy_operator_throwable(type) (::PackedException<type>&& exception_object_private_and_secret)
#define lucy_operator_detect(type, instance) ::PackedException<type>(instance, exception_object_private_and_secret)
#define lucy_throwable_parameter exception_object_private_and_secret
#endif