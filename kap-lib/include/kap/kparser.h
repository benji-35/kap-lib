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

typedef struct knode_yml_s knode_yml;
typedef struct kyml_parser_s kyml_parser_t;

//les structure YML

struct knode_yml_s {
    string path;
    string value;
    knode_yml *next;
    knode_yml *prev;
    kyml_parser_t *master;
};
struct kyml_parser_s {
    knode_yml *nodeList;
    string path;
};

//les fonctions YML

extern void add_yml_node(string path, string value, kyml_parser_t *parser);
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

#endif /*_YML_FUNC_PARSER_*/
#ifdef __cplusplus
}
#endif

#endif /* !KPARSER_H_ */

/*

Pour le YML :

    structure main :
        - Path du fichier
        - Liste des nodes
    
    structure Node de modif :
        - Path
        - Valeur


    fonction init :
    Malloc la structure main
    lire le fichier
    initialiser la liste des nodes

    fonction get value :
        prendre la path donné
        tant que liste node -> next != null
        +->[node->path == path donne] -OUI--> return node->value
        |
        NON
        |
        +-> node = node->next;
        Fin tant
        return NULL;
    
    fonction set value :
        [path exists ?] -OUI--> aller à la node dans la liste et donner la valeur
        |
        NON
        |
        +->Créer une nouvelle node avec le path donné et sa valeur

    fonction pathExists :
        node = getNodeInList
        [node == NULL] -OUI--> return false
        return true

    fonction getNodeInList :
        tant que liste node -> next != NULL
        |
        +->[node->path == path donne] -OUI--> return true
        |
        +-> node = node -> next
        Fin tant que
        return NULL

    fonction trierListeNode :
        il faut trier pour faire en sorte que chaque noeud dans le path soit les un à la suite des autres

    fonction save :
        trierListeNode
        écrire dans le fichier (chaque apparition de '.' sera modifer par un \n + YML_SPC)
*/