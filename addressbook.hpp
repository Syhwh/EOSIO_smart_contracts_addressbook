#pragma once
#include <eosio/eosio.hpp>
#include "addresstable.hpp"

using namespace eosio;

class [[eosio::contract("addressbook")]] addressbook : public contract
{
public:
  using contract::contract;
  addressbook(name self_contract, name user, datastream<const char *> ds);

  [[eosio::action]] void adduser(name user, std::string first_name, std::string last_name,
                                 std::string street, std::string city, std::string state);

  [[eosio::action]] void deleteuser(name user);

private:
  person_t at;
};