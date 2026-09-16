#include    <unistd.h>
#include    <stdlib.h>

typedef struct s_list
{
    char    *value;
    struct s_list *next;
}   t_node;

void    freelist(t_node **head)
{
    t_node  *tmp;
 
    while (*head)
    {
        tmp = (*head)->next;
        free(*head);
        *head = tmp;
    }
    write(1, "\n----- free sucssec -----", 25);
}

void    putnode(char *str)
{
    int     i;

    i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
    write(1, "\n", 1);
}

int     comp(char *s1, char *s2)
{
    int     i;

    i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    return (s1[i] - s2[i]);
}

void    revnode(t_node **head)
{
    t_node  *save;
    t_node  *node1;
    t_node  *node2;
    t_node  *final;
    int     swap;

    swap = 1;
    if (*head == NULL)
        return ;
    while (swap)
    {
        swap = 0;
        save = NULL;
        node1 = *head;
        while (node1->next)
        {
            node2 = node1->next;
            if (comp(node1->value, node2->value) > 0)
            {
                final = node2->next;
                node1->next = final;
                node2->next = node1;
                if (save)
                    save->next = node2;
                else
                    *head = node2;
                save = node2;
                swap = 1;
            }
            else
            {
                save = node1;
                node1 = node1->next;
            }
        }

    }
}

void    insert_at (t_node **head, char *value, int index)
{
    t_node  *serch;
    t_node  *save;
    t_node  *new;
    int     i;

    i = 0;
    new = malloc(sizeof(t_node));
    if (new == NULL)
        return;
    serch = *head;
    save = NULL;
    if (i == index || *head == NULL)
    {
        save = *head;
        *head = new;
        new->value = value;
        new->next = save;
        return ;
    }
    while (i != index && serch)
    {
        save = serch;
        serch = serch->next;
        i++;
    }
    save->next = new;
    new->value = value;
    new->next = serch;
    return;
}

void    creat_node(t_node **head, char *av)
{
    t_node  *serch;
    t_node  *new;

    new = malloc(sizeof(t_node));
    if (new == NULL)
        return ;
    new->value = av;
    new->next = NULL;
    if(*head == NULL)
    {
        *head = new;
        return ;
    }
    serch = *head;
    while (serch->next != NULL)
        serch = serch->next;
    serch->next = new;
    return ;
}

int     main(int ac, char **av)
{
    t_node  *head;
    t_node  *cur;
    char    *value="kac";
    int     index;
    int     i;

    head = NULL;
    i = 1;
    index = 1;
    while (i < ac)
    {
        creat_node(&head, av[i]);
        i++;
    }
    write(1, "----- list sucssec -----\n", 25);
    cur = head;
    while (cur)
    {
        putnode(cur->value);
        cur = cur->next;
    }
    insert_at(&head, value, index);
    write(1, "----- new  sucssec -----\n", 25);
    cur = head;
    while (cur)
    {
        putnode(cur->value);
        cur = cur->next;
    }
    write(1, "----- rev secssec -----\n", 24);
    revnode(&head);
    cur = head;
    while (cur)
    {
        putnode(cur->value);
        cur = cur->next;
    }
    freelist(&head);
    return (0);
}
