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
    string name;
    string value;
    yml_content_t **content;
};

struct kyml_parser_s {
    string path;
    text content;
    yml_content_t **content_yml;
};

yml_content_t *create_yml_content(yml_content_t ***list, string name);
void set_value(kyml_p *parser, string path, string value);
void destroy_path_content(kyml_p *parser, string path);
void destroy_yml_parser(kyml_p *parser);
yml_content_t *search_content_yml(int id, text txt, yml_content_t **li);
string create_yml_array(text txt);

ksize_t nb_yml_content(yml_cont_t **cont);
#endif /*!_KYML_PARSER*/

#endif /* !KPARSER_H_ */
