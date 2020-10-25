#include <eosio/eosio.hpp>
#include "./addressbook.hpp"

using namespace eosio;

addressbook::addressbook(name self_contract, name user, datastream<const char *> sd)
		: contract(self_contract, user, sd), at(self_contract, self_contract.value) {}

void addressbook::adduser(name user, std::string first_name, std::string last_name, uint64_t age,
													std::string street, std::string city, std::string state)
{
	require_auth(user);
	auto iterator = at.find(user.value);
	if (iterator == at.end())
	{
		at.emplace(user, [&](auto &row) {
			row.key = user;
			row.first_name = first_name;
			row.last_name = last_name;
			row.age = age;
			row.street = street;
			row.city = city;
			row.state = state;
		});
	}
	else
	{
		at.modify(iterator, user, [&](auto &row) {
			row.key = user;
			row.first_name = first_name;
			row.last_name = last_name;
			row.age = age;
			row.street = street;
			row.city = city;
			row.state = state;
		});
	}
	print_f("User  %  % was added \n", first_name, last_name);
}

void addressbook::deleteuser(name user)
{
	require_auth(user);
	auto iterator = at.find(user.value);
	check(iterator != at.end(), "User does not exist");
	at.erase(iterator);
	print_f("user % was deleted", user);
}