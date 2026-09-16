#include    <unistd.h>
#include    <stdlib.h>

int     comp(char *str, char *str2)
{
    int     i;

    i = 0;
    while(str[i] && str2[i] && str[i] == str2[i])
        i++;
    return (str[i] - str2[i]);
}

void    pstr(char *str)
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

typedef struct s_list
{
    char     *age;
    struct s_list *next;
}   t_node;

void    freelist(t_node **head)
{
    t_node    *tmp;

    while (*head)
    {
        tmp = (*head)->next;
        free(*head);
        *head = tmp;
    }
}

void    add_node(char **av, int ac, t_node **head)
{
    t_node      *newNode;
    t_node      *finde;

    newNode = malloc(sizeof(t_node));
    if (newNode == NULL)
    {
        write(1, "newNode faile", 13);
        return ;
    }
    newNode->age = av[ac];
    newNode->next = NULL;
    finde = *head;
    if (*head == NULL)
    {
        *head = newNode;
        return ;
    }
    else
    {
        while (finde->next != NULL)
            finde = finde->next;
        finde->next = newNode;
    }
}

void    dell_node(char *av, t_node **head)
{
    t_node      *serch;
    t_node      *save;

    serch = *head;
    save = NULL;
    if (serch == NULL)
    {
        write(1, "no node dell\n", 13);
        return ;
    }
    if(comp(serch->age, av) == 0)
    {
        *head = serch->next;
        free(serch);
        write(1, "first node is dell\n", 19);
        return ;
    }
    while (serch != NULL && comp(serch->age, av))
    {
        save = serch;
        serch = serch->next;
    }
    if (serch == NULL)
    {
        write(1, "not fond\n", 9);
        return ;
    }
    save->next = serch->next;
    free(serch);
    return ;
}
int     main(int ac, char **av)
{
    t_node  *head;
    t_node  *cur;
    int     i;

    i = 1;
    head = NULL;
    if (ac < 2)
    {
        write(1, "No node", 7);
        return (0);
    }
    while (i < (ac - 1))
    {
        add_node(av, i, &head);
        i++;
    }
    cur = head;
    while (cur != NULL)
    {
        pstr(cur->age);
        cur = cur->next;
    }
    write(1, "--- delete ---\n", 15);
    dell_node(av[ac - 1], &head);
    cur = head;
    while (cur != NULL)
    {
        pstr(cur->age);
        cur = cur->next;
    }
    write(1, "--- free ---\n", 13);
    freelist(&head);
    return (0);
}
