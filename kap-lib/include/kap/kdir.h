/*
** EPITECH PROJECT, 2022
** C-Lib
** File description:
** kdir
*/

#ifndef KDIR_H_
    #define KDIR_H_

    #include "kap/klist.h"
    #include "kap/kstr.h"

    #ifndef KFILE_TYPE
        #define KFILE_TYPE
        typedef enum kfile_type_e {
            KDIR = 0,
            KFILE,
            KLINK,
            KEXEC,
            KSOCKET,
            KPIPE,
            KUNKNOWN
        } kfile_type_t;

    #endif

    struct kdir_s {
        string _path;
        klist_t *_content;
    };

    struct kfile_s {
        string _name;
        string _path;
        string _ext;
        kfile_type_t _type;
    };

    typedef struct kdir_s kdir_t;
    typedef struct kfile_s kfile_t;

    #ifndef KDIR_FUNCTIONS
        #define KDIR_FUNCTIONS

        kdir_t *getDirectory(cstring path);
        void remove_dir(kdir_t *dir);
        klist_t *getFiles(kdir_t *dir);

        text get_file_content(kfile_t *file);

        void update_dir(kdir_t *dir);
    #endif

#endif /* !KDIR_H_ */
