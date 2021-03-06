/*
 * Copyright 2013-2018, Corvusoft Ltd, All Rights Reserved.
 */

#pragma once

//System Includes
#include <map>
#include <memory>
#include <string>
#include <sstream>
#include <functional>
#include <type_traits>

//Project Includes

//External Includes
#include <corvusoft/core/byte.hpp>

//System Namespaces

//Project Namespaces

//External Namespaces

namespace corvusoft
{
    //Forward Declarations
    
    namespace restless
    {
        //Forward Declarations
        namespace detail
        {
            struct ResponseImpl;
        }
        
        class Response final
        {
            public:
                //Friends
                
                //Definitions
                
                //Constructors
                Response( void );
                
                virtual ~Response( void );
                
                //Functionality
                bool has_header( const std::string& name ) const;
                
                //Getters
                double get_version( void ) const;
                
                int get_status_code( void ) const;
                
                std::string get_status_message( void ) const;
                
                std::string get_protocol( void ) const;
                
                core::Bytes get_body( void ) const;
                
                template < typename Type, typename enable = std::enable_if_t < std::is_arithmetic< Type >::value && ! std::is_same< Type, char >::value, Type > >
                Type get_header( const std::string& name, const Type default_value ) const
                {
                    std::istringstream stream( get_header( name ) );
                    
                    Type parameter;
                    stream >> parameter;
                    
                    return ( stream.fail( ) ) ? default_value : parameter;
                }
                
                std::string get_header( const std::string& name, const std::string& default_value = "" ) const;
                
                std::multimap< std::string, std::string > get_headers( const std::string& name = "" ) const;
                
                //Setters
                void set_version( const double value );
                
                void set_status_code( const int value );
                
                void set_status_message( const std::string& value );
                
                void set_protocol( const std::string& value );
                
                void set_body( const std::string& value );
                
                void set_body( const core::Bytes& value );
                
                void set_header( const std::string& name, const std::string& value );
                
                void set_headers( const std::multimap< std::string, std::string >& values );
                
                //Operators
                
                //Properties
                
            protected:
                //Friends
                
                //Definitions
                
                //Constructors
                
                //Functionality
                
                //Getters
                
                //Setters
                
                //Operators
                
                //Properties
                
            private:
                //Friends
                
                //Definitions
                
                //Constructors
                Response( const Response& original ) = delete;
                
                //Functionality
                
                //Getters
                
                //Setters
                
                //Operators
                Response& operator =( const Response& value ) = delete;
                
                //Properties
                std::unique_ptr< detail::ResponseImpl > m_pimpl;
        };
    }
}
