#include "fioqueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    if (argc < 4)
    {
        printf("Неправильное кол-во аргуметов %d: ожидалось > 3", argc);
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1], "save") == 0)
    {
        if ((strcmp(argv[2], "-t") == 0) || (strcmp(argv[2], "--text") == 0))
        {

            tdQueue *q = rand_gen_matrix2d_in_queue(ELEMENTS);
            save_queue_to_file(argv[3], q, TEXT_MODE);

            QueueIterator *it = queue_iterator_create(q, 0);
            for (int i = 0; i < q->size; i++)
            {
                destroy_matrix2d(queue_iterator_next(it), 1);
            }
            free(it);
            queue_free(q);
        }
        else if ((strcmp(argv[2], "-b") == 0) || (strcmp(argv[2], "--binary") == 0))
        {

            tdQueue *q = rand_gen_matrix2d_in_queue(ELEMENTS);
            save_queue_to_file(argv[3], q, BINARY_MODE);

            QueueIterator *it = queue_iterator_create(q, 0);
            for (int i = 0; i < q->size; i++)
            {
                destroy_matrix2d(queue_iterator_next(it), 1);
            }
            free(it);
            queue_free(q);
        }
        else
        {
            printf("Неизвестный аргумент '%s': \
ожидалось (-t, --text, -b, --binary)\n",
                   argv[2]);
            exit(EXIT_FAILURE);
        }
    }
    else if (strcmp(argv[1], "load") == 0)
    {
        if ((strcmp(argv[2], "-t") == 0) || (strcmp(argv[2], "--text") == 0))
        {
            tdQueue *q = load_queue_from_file(argv[3], TEXT_MODE);
            printf("Размер очереди: %d\n", queue_size(q));
            QueueIterator *it = queue_iterator_create(q, 0);
            Matrix2d *m;
            int i = 0;
            while ((m = queue_iterator_next(it)) != NULL)
            {
                printf("%d\n", i++);
                show_matrix2d(m);
            }
            free(it);
            QueueIterator *it2 = queue_iterator_create(q, 0);
            for (int i = 0; i < q->size; i++)
            {
                destroy_matrix2d(queue_iterator_next(it2), 1);
            }
            free(it2);
            queue_free(q);
        }
        else if ((strcmp(argv[2], "-b") == 0) || (strcmp(argv[2], "--binary") == 0))
        {

            tdQueue *q = load_queue_from_file(argv[3], BINARY_MODE);
            printf("Размер очереди: %d\n", queue_size(q));
            QueueIterator *it = queue_iterator_create(q, 0);
            Matrix2d *m;
            int i = 0;
            while ((m = queue_iterator_next(it)) != NULL)
            {
                printf("%d\n", i++);
                show_matrix2d(m);
            }
            free(it);
            QueueIterator *it2 = queue_iterator_create(q, 0);
            for (int i = 0; i < q->size; i++)
            {
                destroy_matrix2d(queue_iterator_next(it2), 1);
            }
            free(it2);
            queue_free(q);
        }
        else
        {
            printf("Неизвестный аргумент '%s': \
ожидалось (-t, --text, -b, --binary)\n",
                   argv[2]);
            exit(EXIT_FAILURE);
        }
    }
    else if (strcmp(argv[1], "list") == 0)
    {
        if ((strcmp(argv[2], "-t") == 0) || (strcmp(argv[2], "--text") == 0))
        {
            tdQueue *q = load_queue_from_file(argv[3], TEXT_MODE);
            printf("Размер очереди: %d\n", queue_size(q));
            QueueIterator *it = queue_iterator_create(q, 0);
            Matrix2d *m;
            int i = 0;
            while ((m = queue_iterator_next(it)) != NULL)
            {
                printf("Index %d - %p\n", i++, m);
            }
            free(it);
            QueueIterator *it2 = queue_iterator_create(q, 0);
            for (int i = 0; i < q->size; i++)
            {
                destroy_matrix2d(queue_iterator_next(it2), 1);
            }
            free(it2);
            queue_free(q);
        }
        else if ((strcmp(argv[2], "-b") == 0) || (strcmp(argv[2], "--binary") == 0))
        {

            tdQueue *q = load_queue_from_file(argv[3], BINARY_MODE);
            printf("Размер очереди: %d\n", queue_size(q));
            QueueIterator *it = queue_iterator_create(q, 0);
            Matrix2d *m;
            int i = 0;
            while ((m = queue_iterator_next(it)) != NULL)
            {
                printf("Index %d - %p\n", i++, m);
            }
            free(it);
            QueueIterator *it2 = queue_iterator_create(q, 0);
            for (int i = 0; i < q->size; i++)
            {
                destroy_matrix2d(queue_iterator_next(it2), 1);
            }
            free(it2);
            queue_free(q);
        }
        else
        {
            printf("Неизвестный аргумент '%s': \
ожидалось (-t, --text, -b, --binary)\n",
                   argv[2]);
            exit(EXIT_FAILURE);
        }
    }
    else if (strcmp(argv[1], "get") == 0)
    {
        if (argc != 5)
        {
            printf("Неправильное кол-во аргуметов %d: ожидалось 5\n", argc);
            exit(EXIT_FAILURE);
        }
        else
        {
            if ((strcmp(argv[2], "-t") == 0) || (strcmp(argv[2], "--text") == 0))
            {
                Matrix2d *m = get_matrix2d_from_text_file(argv[4], (int)*argv[3] - '0');
                show_matrix2d(m);
                show_bitrgbled_bits(m->settings);
                destroy_matrix2d(m, true);
            }
            else if ((strcmp(argv[2], "-b") == 0) || (strcmp(argv[2], "--binary") == 0))
            {
                Matrix2d *m = matrix2d_default_constructor();
                get_matrix2d_from_binary_file(argv[4], (int)*argv[3] - '0', m);
                show_matrix2d(m);
                show_bitrgbled_bits(m->settings);
                destroy_matrix2d(m, true);
            }
            else
            {
                printf("Неизвестный аргумент '%s': \
ожидалось (-t, --text, -b, --binary)\n",
                       argv[2]);
                exit(EXIT_FAILURE);
            }
        }
    }
    else
    {
        printf("Неизвестный аргумент '%s': \
ожидалось (save, load, list, get)\n",
               argv[1]);
        exit(EXIT_FAILURE);
    }

    return 0;
}
