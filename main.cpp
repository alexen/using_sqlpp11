#include <iostream>
#include <memory>
#include <boost/exception/diagnostic_information.hpp>
#include <sqlpp11/postgresql/connection.h>
#include <sqlpp11/transaction.h>
#include <sqlpp11/select.h>
#include <sqlpp11/insert.h>

#include "person.h"

int main()
{
     try
     {
          const auto connCfg = std::make_shared< sqlpp::postgresql::connection_config >();

          connCfg->host = "postgres";
          connCfg->port = 6432;
          connCfg->dbname = "test";
          connCfg->user = "test";
          connCfg->password = "test123456";

          sqlpp::postgresql::connection db( connCfg );

          auto tr = sqlpp::start_transaction( db, false );

          using_sqlpp11::Person p;

          db( sqlpp::insert_into( p ).set( p.lastName = "Ericsson", p.firstName = "Jahnes" ) );

          for( const auto& row: db( sqlpp::select( sqlpp::all_of( p ) ).from( p ).where( p.lastName == "Ericsson" ) ) )
               std::cout << row.id << ": " << row.lastName << ' ' << row.firstName << '\n';

          tr.commit();
     }
     catch( const std::exception& e )
     {
          std::cerr << "exception: " << boost::diagnostic_information( e ) << '\n';
          return 1;
     }

     return 0;
}
