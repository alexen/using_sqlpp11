#ifndef USING_SQLPP_PERSON_H
#define USING_SQLPP_PERSON_H

#include <sqlpp11/table.h>
#include <sqlpp11/column_types.h>
#include <sqlpp11/char_sequence.h>

namespace using_sqlpp11 {
namespace Person_ {
struct Id
{
     struct _alias_t
     {
          static constexpr const char _literal[] = "id";
          using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
          template< typename T >
          struct _member_t
          {
               T id;
               T& operator()()
               {
                    return id;
               }
               const T& operator()() const
               {
                    return id;
               }
          };
     };
     using _traits = sqlpp::make_traits<sqlpp::integer>;
};


struct LastName
{
     struct _alias_t
     {
          static constexpr const char _literal[] = "last_name";
          using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
          template< typename T >
          struct _member_t
          {
               T lastName;
               T& operator()()
               {
                    return lastName;
               }
               const T& operator()() const
               {
                    return lastName;
               }
          };
     };
     using _traits = sqlpp::make_traits<sqlpp::varchar, sqlpp::tag::require_insert>;
};


struct FirstName
{
     struct _alias_t
     {
          static constexpr const char _literal[] = "first_name";
          using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
          template< typename T >
          struct _member_t
          {
               T firstName;
               T& operator()()
               {
                    return firstName;
               }
               const T& operator()() const
               {
                    return firstName;
               }
          };
     };
     using _traits = sqlpp::make_traits<sqlpp::varchar, sqlpp::tag::require_insert>;
};


struct MiddleName
{
     struct _alias_t
     {
          static constexpr const char _literal[] = "middle_name";
          using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
          template< typename T >
          struct _member_t
          {
               T middleName;
               T& operator()()
               {
                    return middleName;
               }
               const T& operator()() const
               {
                    return middleName;
               }
          };
     };
     using _traits = sqlpp::make_traits<sqlpp::varchar, sqlpp::tag::can_be_null>;
};
}

struct Person: sqlpp::table_t< Person, Person_::Id, Person_::LastName, Person_::FirstName, Person_::MiddleName >
{
     struct _alias_t
     {
          static constexpr const char _literal[] = "person";
          using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
          template< typename T >
          struct _member_t
          {
               T person;
               T& operator()()
               {
                    return person;
               }
               const T& operator()() const
               {
                    return person;
               }
          };
     };
};
}
#endif
