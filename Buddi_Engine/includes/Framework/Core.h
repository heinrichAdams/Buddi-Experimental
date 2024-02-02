#ifndef CORE_H
#define CORE_H

#include <memory>
#include <map>
#include <unordered_map>
#include <vector>

namespace Buddi_Base
{
	// Unique Pointer
	template<typename T>
	using unique = std::unique_ptr<T>;

	// Shared Pointer
	template<typename T>
	using shared = std::shared_ptr<T>;

	// Weak Pointer
	template<typename T>
	using weak = std::weak_ptr<T>;

	// List Datatype
	template<typename T>
	using List = std::vector<T>;

	// Map Datatype
	template<typename key, typename value, typename predicate = std::less<key>>
	using Map = std::map<key, value, predicate>;

	// Hash Map Datatype
	template<typename key, typename value, typename hash = std::hash<key>>
	using HashMap = std::map<key, value, hash>;


	//Logging Macro
	#define LOG(L, ...) printf(L "\n", ##__VA_ARGS__)
}

#endif

