/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** kparser
*/

#ifndef KPARSER_H_
#define KPARSER_H_

#include <kap/kutils.h>
#include <kap/kstr.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _KJSON_PARSER_
#define _KJSON_PARSER_

typedef struct kparser_main_s kjson_parser_t;
typedef struct knode_main_parser_s knode_json_t;

///initialize json parser
/// @param path -> path of json file
extern kjson_parser_t *init_json_parser(cstring path);

#endif /*!_KJSON_PARSER_*/

#ifndef _KXML_PARSER
#define _KXML_PARSER
#endif /*!_KXML_PARSER*/

#ifndef _KYML_PARSER
#define _KYML_PARSER

#ifndef _YML_SPACES_
#define _YML_SPACES_ 2
#endif /*!_YML_SPACES_*/

#define YML_SPC _YML_SPACES_

typedef struct knode_main_parser_s knode_yml;
typedef struct kparser_main_s kyml_parser_t;

struct knode_main_parser_s {
    string path;
    string value;
    knode_yml *next;
    knode_yml *prev;
    kyml_parser_t *master;
    text unixistant_pathes;
};
struct kparser_main_s {
    knode_yml *nodeList;
    string path;
};

//les fonctions YML

extern void add_yml_node(cstring path, string value, kyml_parser_t *parser);
extern void smart_add_yml_node(cstring path UNUSED, string value UNUSED, kyml_parser_t *parser UNUSED);
extern knode_yml *get_last_yml_node(kyml_parser_t *parser);
extern void display_yml_content(kyml_parser_t *parser);
extern void init_yml_nodelist(kyml_parser_t *parser);
extern knode_yml *get_yml_node(cstring path, kyml_parser_t *parser);
extern void remove_nodeYML(cstring path, kyml_parser_t *parser);
///check if node exists with path 
extern bool node_yml_exists(cstring path, kyml_parser_t *parser);
///initialize the yml parser by file path
extern kyml_parser_t *init_yml_parser(cstring path);
//destroy all things in parser
extern void destroy_yml_parser(kyml_parser_t *parser);
//to set value in yml parser
extern void set_value_YML(cstring path, string value, kyml_parser_t *parser);
///save paser
extern void save_yml_parser(kyml_parser_t *parser);
///get yml value
extern string get_value_YML(cstring path, kyml_parser_t *parser);
///save yml parser in another file
extern void save_yml_parser_of(kyml_parser_t *parser, cstring path);

#endif /*_YML_FUNC_PARSER_*/

#ifndef _CONF_PARSER
#define _CONF_PARSER

#ifndef _CONF_PARSER_STRUCTURES
#define _CONF_PARSER_STRUCTURES

//define all conf parser structure

typedef struct kconf_parser_s kconf_parser_t;

struct kconf_parser_s {
    string path;
    text content;
    bool auto_save;
};


#endif /*_CONF_PARSER_STRUCTURES*/

#ifndef _CONF_PARSER_FUNCTIONS
#define _CONF_PARSER_FUNCTIONS

//define all conf parser fucntions

///Save the content of parser
///@param parser -> parser of conf file
extern void save_conf_parser(kconf_parser_t *parser);

///Free the parser of conf file
///@param parser -> parser of conf file
extern void free_conf_parser(kconf_parser_t *parser);

///add a value or set value in conf file
///@param parser -> parser of conf file
///@param key -> key that get value
///@param value -> string that content the value to save
extern void add_value_conf(kconf_parser_t *parser, cstring key, string value);

///get value in conf file
///@param parser -> parser of conf file
///@param key -> key that content value
///@return string that content value. If key does not found, function return an empty string. The return value need to be free
extern string get_value_conf(kconf_parser_t *parser, cstring key);

///set auto save value
///@param parser -> parser of conf file
///@param val_autosave -> value of auto save
extern void set_autosave_kconf_parser(kconf_parser_t *parser, bool val_autosave);

///initialize config file parser
///@param path -> path of file config
///@return parser or null
extern kconf_parser_t *init_kconf_parser(cstring path);

#endif /*_CONF_PARSER_FUNCTIONS*/

#endif /*_CONF_PARSER*/

#ifdef __cplusplus
}
#endif

#endif /* !KPARSER_H_ */
