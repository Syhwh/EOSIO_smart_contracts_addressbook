#pragma once
#include <eosio/eosio.hpp>

struct [[eosio::table]] person
{
	eosio::name key;
	std::string first_name;
	std::string last_name;
	std::string street;
	std::string city;
	std::string state;

	uint64_t primary_key() const
	{
		return key.value;
	}
	EOSLIB_SERIALIZE(person,
									 (first_name)(last_name)(street)(city)(state));
};

using person_t = eosio::multi_index<"people"_n, person>;
//  typedef eosio::multi_index<"people"_n, person> person_t;