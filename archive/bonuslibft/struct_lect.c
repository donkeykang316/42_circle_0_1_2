
typedef struct s_person
{
    char    *name;
    int     age;
    char    *hobby;
    struct s_list *next;
} t_person;



1. Element:
typedef struct s_person
{
    char    "Florian";
    int     32;
    char    "climbing";
    struct s_list 2.Element;
} t_person;

2. Element:
typedef struct s_person
{
    char    "Kang";
    int     34;
    char    "kindergarten";
    struct s_list NULL;
} t_person;




int main(int argc, char **argv)
{
    t_person*   person;
    t_person*   tmp;

    person = initializeList(argv);
    tmp = person;
    while ( person )
    {
        if (person->name == "Kang")
            break;
        person = person->next;
    }

    if (person)
        printf("found the name\n");
    else
        printf("didn't find it\n");

}