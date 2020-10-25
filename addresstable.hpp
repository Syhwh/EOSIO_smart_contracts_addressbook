// #pragma once
#include <eosio/eosio.hpp>

struct [[eosio::table("person")eosio::contract("addressbook")]] person
{
	eosio::name key;
	std::string first_name;
	std::string last_name;
	std::string street;
	std::string city;
	std::string state;
	uint64_t age;

	uint64_t primary_key() const { return key.value; }
	uint64_t get_secondary_1() const { return age; }

	// EOSLIB_SERIALIZE(person,
	// 								 (first_name)(last_name)(street)(city)(state)(age));
};


using person_t = eosio::multi_index<"people"_n, person,
eosio::indexed_by<"byage"_n, eosio::const_mem_fun<person, uint64_t, &person::get_secondary_1>>
>;

// using person_t = eosio::multi_index<"people"_n, person>; // single index
//  typedef eosio::multi_index<"people"_n, person> person_t;