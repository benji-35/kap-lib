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
    yml_content_t **content;
};

struct kyml_parser_s {
    string path;
    text content;
    yml_content_t content_yml;
};

struct read_yml_line {
    int id_line;
    int spaces_before;
    string content;
};

#endif /*!_KYML_PARSER*/

#ifndef _YML_FUNC_PARSER_
#define _YML_FUNC_PARSER_

extern kyml_p *init_kyml_parser(cstring path);
extern yml_content_t *get_last_yml_content(kyml_p *parser);
extern string get_value_yml(kyml_p *parser, cstring path);
extern text get_array_yml(kyml_p *parser, cstring path);

#endif /*_YML_FUNC_PARSER_*/
#ifdef __cplusplus
}
#endif

#endif /* !KPARSER_H_ */
