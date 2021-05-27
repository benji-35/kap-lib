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

#ifndef _KJSON_PARSER_
#define _KJSON_PARSER_
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
typedef struct kyml_parser_s kyml_parser_t;
typedef kyml_parser_t kyml_p;
typedef struct yml_content_s yml_content_t;
typedef yml_content_t yml_cont_t;

struct yml_content_s {
    ksize_t depth;
    string name;
    string value;
    ksize_t depth;
    yml_content_t **content;
};

struct kyml_parser_s {
    string path;
    text content;
    yml_content_t **content_yml;
};

/// create new node of yml
/// @param list > pointer on current list of node
/// @param name > name of the node
/// @param depth > current depth
/// @return yml_node created
yml_content_t *create_yml_content(yml_content_t ***list, string name, ksize_t depth);

/// set value to node
/// @param parser > pointer on yml parser
/// @param path > path of node
/// @param value > value to give (string value)
void set_value(kyml_p *parser, string path, string value);

/// destroy a yml node
/// @param parser > pointer on yml parser
/// @param path > path of node
void destroy_yml_node(kyml_p *parser, string path);

/// free all yml parser
/// @param parser > pointer on yml parser
void destroy_yml_parser(kyml_p *parser);

/// search a yml node in parser
/// @param id > current id node detected
/// @param txt > list of name node (path but split)
/// @param li > list of nodes in current node
/// @return yml_node created
yml_content_t *search_content_yml(int id, text txt, yml_content_t **li);

/// create an array for yml parser with a text
/// @param txt > list of informations as string
/// @return the array created
string create_yml_array(text txt);

/// calcul nb yml node in list of nodes
/// @param cont > list of nodes
/// @return the number of nodes
ksize_t nb_yml_content(yml_cont_t **cont);

/// init a new yml parser
/// @param path > path of yml file
/// @return the parser
kyml_p *init_yml_parser(string path);

/// find last yml node added with a specific depth
/// @param parser > parser yml
/// @param depth > depth of last node want
/// @return yml node found. If function not found node, return NULL
yml_cont_t *find_last_yml_node_by_index(kyml_p *parser, ksize_t depth);

/// find last yml node added with a specific depth with list of yml node
/// @param list > parser yml
/// @param depth > depth of last node want
/// @return yml node found. If function not found node, return NULL
yml_cont_t *flast_nyml_bindex(yml_cont_t **list, ksize_t depth);
#endif /*!_KYML_PARSER*/

#endif /* !KPARSER_H_ */
