#pragma once

#include <memory>

#ifdef IMAGINE_PLATFORM_WINDOWS
#if IMAGINE_DYNAMIC_LINK
	#ifdef IMAGINE_BUILD_DLL
		#define IMAGINE_API __declspec(dllexport)
	#else
		#define IMAGINE_API __declspec(dllimport)
	#endif
#else
	#define IMAGINE_API
#endif
#else
	#error Imaginengion Only supports Windows !
#endif

#ifdef IMAGINE_DEBUG
	#define IMAGINE_ENABLE_ASSERTS
#endif

#ifdef IMAGINE_ENABLE_ASSERTS
	#define IMAGINE_ASSERT(x, ...) { if(!(x)) {IMAGINE_ERROR("Assertion Failed: {}", __VA_ARGS__); __debugbreak(); } }
	#define IMAGINE_CORE_ASSERT(x, ...) { if(!(x)) {IMAGINE_CORE_ERROR("Assertion Failed: {}", __VA_ARGS__); __debugbreak(); } }
#else
	#define IMAGINE_ASSERT(x, ...)
	#define IMAGINE_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

namespace IM {

	template<typename T>
	using ScopePtr = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr ScopePtr<T> CreateScopePtr(Args&& ... args) {
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using RefPtr = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr RefPtr<T> CreateRefPtr(Args&& ... args) {
		return std::make_shared<T>(std::forward<Args>(args)...);
	}


}