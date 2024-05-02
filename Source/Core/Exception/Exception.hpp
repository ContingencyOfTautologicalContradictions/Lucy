#ifndef lucy_core_exception_exception
#define lucy_core_exception_exception
#define informer(...) ([[maybe_unused]] ::Exception& exception_object_private_and_secret __VA_OPT__(,) __VA_ARGS__)
#define throwable(...) ([[maybe_unused]] ::Exception& exception_object_private_and_secret __VA_OPT__(,) __VA_ARGS__)
#define record if([[maybe_unused]] ::Exception exception_object_private_and_secret; exception_object_private_and_secret_stub)
#define attempt exception_object_private_and_secret = [&]
#define pass(...) (exception_object_private_and_secret __VA_OPT__(,) __VA_ARGS__)
#define grab(...) (exception_object_private_and_secret __VA_OPT__(,) __VA_ARGS__)
#define eject exception_object_private_and_secret =
#define handle(first, ...) if(exception_object_private_and_secret.Thrown() and exception_object_private_and_secret.Catch(first __VA_OPT__(,) __VA_ARGS__))
#define any if(exception_object_private_and_secret.Any())
#define finally if(exception_object_private_and_secret.Finally())
#define recover(type) static_cast<type>(exception_object_private_and_secret)
#define anomaly(name) enum class [[nodiscard]] name : unsigned short
#define message exception_object_private_and_secret.Message()
#endif