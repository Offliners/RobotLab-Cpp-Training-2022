#include<iostream>

#define LENGTH 6

typedef struct CUSTOMER
{
    int id;
    struct CUSTOMER *prev;
    struct CUSTOMER *next;
} Customer;

typedef struct CUSTOMER_QUEUE
{
    Customer *head;
    Customer *tail;
} Customer_Queue;

typedef struct GROUP
{
    int group_id;
    struct GROUP *prev;
    struct GROUP *next;
    Customer_Queue *customer_queue;
} Group;

typedef struct GROUP_QUEUE
{
    Group *head;
    Group *tail;
    Group **group_arr;
} Group_Queue;

typedef struct MCDONALDS
{
    int is_close;
    Group_Queue *group_queue;
} McDonalds;

void McDonalds_init(McDonalds *mcdonalds, int M, int K);
Group *Group_init(int group_id, int customer_id);
void enter(McDonalds *mcdonalds, int group_id, int customer_id, int mcdonalds_id);
Group *find_same_group(McDonalds *mcdonalds, int group_id, int mcdonalds_id);
void join_same_group(Group *group, int customer_id);
void print_mcdonalds(McDonalds *mcdonalds, int mcdonalds_id);
void leave(McDonalds *mcdonalds, int mcdonalds_id);
void go(McDonalds *mcdonalds, int mcdonalds_id);
void close(McDonalds *mcdonalds, int mcdonalds_id, int M);

using namespace std;

int main(void)
{
    int M, N, K;


    cin >> M >> N >> K;
    cin.get();
    
    McDonalds *mcdonalds = new McDonalds[M]; // (Bathroom*)malloc(M * sizeof(Bathroom));
    McDonalds_init(mcdonalds, M, K);

    for(int i = 0; i < N; ++i)
    {
        char *situation = new char[LENGTH];

        cin >> situation;

        int group_id, customer_id, mcdonalds_id;
        switch(situation[0])
        {
            case 'e':
                cin >> group_id >> customer_id >> mcdonalds_id;
                cin.get();

                enter(mcdonalds, group_id, customer_id, mcdonalds_id);
                break;
            case 'l':
                cin >> mcdonalds_id;
                cin.get();
                
                leave(mcdonalds, mcdonalds_id);
                break;
            case 'g':
                cin >> mcdonalds_id;
                cin.get();
                
                go(mcdonalds, mcdonalds_id);
                break;
            case 'c':
                cin >> mcdonalds_id;
                cin.get();

                close(mcdonalds, mcdonalds_id, M);
                break;
            default:
                printf("Unknown Situation!\n");
                exit(1);
        }

        delete [] situation;
    }

    for(int j = 0; j < M; ++j)
        print_mcdonalds(mcdonalds, j);

    delete [] mcdonalds;
    return 0;
}

void McDonalds_init(McDonalds *mcdonalds, int M, int K)
{
    for(int i = 0; i < M; ++i)
    {
        mcdonalds[i].is_close = 0;

        Group_Queue *group_queue = new Group_Queue;
        group_queue->group_arr = new Group*[const_cast<const int&>(K)];

        for(int j = 0; j < K; ++j)
            group_queue->group_arr[j] = NULL;

        group_queue->head = NULL;
        group_queue->tail = NULL;
        mcdonalds[i].group_queue = group_queue;
    }
}

Group *Group_init(int group_id, int customer_id)
{
    Customer *customer = new Customer;
    customer->id = customer_id;
    customer->prev = NULL;
    customer->next = NULL;

    Customer_Queue *customer_queue = new Customer_Queue;
    customer_queue->head = customer;
    customer_queue->tail = customer;

    Group *group = new Group;
    group->group_id = group_id;
    group->prev = NULL;
    group->next = NULL;
    group->customer_queue = customer_queue;

    return group;
}

void enter(McDonalds *mcdonalds, int group_id, int customer_id, int mcdonalds_id)
{
    if(mcdonalds[mcdonalds_id].group_queue->head == NULL)
    {
        Group *group = Group_init(group_id, customer_id);
        mcdonalds[mcdonalds_id].group_queue->group_arr[group_id] = group;
        mcdonalds[mcdonalds_id].group_queue->head = group;
        mcdonalds[mcdonalds_id].group_queue->tail = group;
    }
    else
    {
        Group *group = find_same_group(mcdonalds, group_id, mcdonalds_id);

        if(group == NULL)
        {
            Group *new_group = Group_init(group_id, customer_id);
            new_group->prev = mcdonalds[mcdonalds_id].group_queue->tail;
            mcdonalds[mcdonalds_id].group_queue->tail->next = new_group;
            mcdonalds[mcdonalds_id].group_queue->tail = new_group;
            mcdonalds[mcdonalds_id].group_queue->group_arr[group_id] = new_group;
        }
        else
            join_same_group(group, customer_id);
    }
}

Group *find_same_group(McDonalds *mcdonalds, int group_id, int mcdonalds_id)
{
    return mcdonalds[mcdonalds_id].group_queue->group_arr[group_id];
}

void join_same_group(Group *group, int customer_id)
{
    Customer *customer = new Customer;
    customer->id = customer_id;
    customer->next = NULL;
    customer->prev = group->customer_queue->tail;
    group->customer_queue->tail->next = customer;
    group->customer_queue->tail = customer;
}

void print_mcdonalds(McDonalds *mcdonalds, int mcdonalds_id)
{
    Group *group = mcdonalds[mcdonalds_id].group_queue->head;

    while(group != NULL)
    {
        Customer *customer = group->customer_queue->head;

        while(customer != NULL)
        {
            cout << customer->id << " ";
            customer = customer->next;
        }
        
        group = group->next;
    }
    cout << endl;
}

void leave(McDonalds *mcdonalds, int mcdonalds_id)
{
    Group_Queue *group_queue = mcdonalds[mcdonalds_id].group_queue;

    if(group_queue->head == group_queue->tail)
    {
        if(group_queue->head->customer_queue->head == group_queue->head->customer_queue->tail)
        {
            group_queue->group_arr[group_queue->head->group_id] = NULL;
            group_queue->tail->customer_queue = NULL;
            group_queue->head = NULL;
            group_queue->tail = NULL;
        }
        else
        {
            Customer *customer = group_queue->head->customer_queue->tail->prev;

            customer->next = NULL;
            group_queue->head->customer_queue->tail = customer;
        }
    }
    else
    {
        if(group_queue->tail->customer_queue->head == group_queue->tail->customer_queue->tail)
        {
            Group *group = group_queue->tail->prev;

            group_queue->group_arr[group_queue->tail->group_id] = NULL;
            group->next = NULL;
            group_queue->tail = group;
        }
        else
        {
            Customer *customer = group_queue->tail->customer_queue->tail->prev;

            customer->next = NULL;
            group_queue->tail->customer_queue->tail = customer;
        }
    }
}

void go(McDonalds *mcdonalds, int mcdonalds_id)
{
    Group_Queue *group_queue = mcdonalds[mcdonalds_id].group_queue;

    if(group_queue->head == group_queue->tail)
    {
        if(group_queue->head->customer_queue->head == group_queue->head->customer_queue->tail)
        {
            group_queue->group_arr[group_queue->head->group_id] = NULL;
            group_queue->head->customer_queue = NULL;
            group_queue->head = NULL;
            group_queue->tail = NULL;
        }
        else
        {
            Customer *customer = group_queue->head->customer_queue->head;
            customer = customer->next;
            customer->prev = NULL;
            group_queue->head->customer_queue->head = customer;
        }
    }
    else
    {
        if(group_queue->head->customer_queue->head == group_queue->head->customer_queue->tail)
        {
            Group *group = group_queue->head;
            group_queue->group_arr[group->group_id] = NULL;
            group = group->next;
            group->prev = NULL;
            group_queue->head = group;
        }
        else
        {
            Customer *customer = group_queue->head->customer_queue->head;
            customer = customer->next;
            customer->prev = NULL;
            group_queue->head->customer_queue->head = customer;
        }
    }
}

void close(McDonalds *mcdonalds, int mcdonalds_id, int M)
{
    mcdonalds[mcdonalds_id].is_close = 1;

    int mcdonalds_index;
    int i = 1;
    int flag = 0;
    while(1)
    {
        mcdonalds_index = (mcdonalds_id - i) < 0 ? mcdonalds_id - i + M : mcdonalds_id - i;
        if(!mcdonalds[mcdonalds_index].is_close)
            break;
        
        ++i;

        if(mcdonalds_index == mcdonalds_id)
        {
            flag = 1;
            break;
        }
    }

    if(!flag)
    {
        Group *reversed_group = mcdonalds[mcdonalds_id].group_queue->tail;
        while(reversed_group != NULL)
        {
            Group *same_group = find_same_group(mcdonalds, reversed_group->group_id, mcdonalds_index);

            if(same_group != NULL)
            {
                Customer *customer = reversed_group->customer_queue->tail;

                while(customer != NULL)
                {
                    join_same_group(same_group, customer->id);
                    customer = customer->prev;
                }
            }
            else
            {
                Group *new_group = Group_init(reversed_group->group_id, reversed_group->customer_queue->tail->id);

                if(mcdonalds[mcdonalds_index].group_queue->head != NULL)
                {
                    new_group->prev = mcdonalds[mcdonalds_index].group_queue->tail;
                    mcdonalds[mcdonalds_index].group_queue->tail->next = new_group;
                    mcdonalds[mcdonalds_index].group_queue->tail = new_group;
                    mcdonalds[mcdonalds_index].group_queue->group_arr[new_group->group_id] = new_group;
                }
                else
                {
                    mcdonalds[mcdonalds_index].group_queue->head = new_group;
                    mcdonalds[mcdonalds_index].group_queue->tail = new_group;
                    mcdonalds[mcdonalds_index].group_queue->group_arr[new_group->group_id] = new_group;
                }

                Customer *customer = reversed_group->customer_queue->tail->prev;
                while(customer != NULL)
                {
                    join_same_group(new_group, customer->id);
                    customer = customer->prev;
                }
                
                delete(customer);
            }

            reversed_group = reversed_group->prev;
        }

        delete(reversed_group);
    }
    
    mcdonalds[mcdonalds_id].group_queue->head = NULL;
    mcdonalds[mcdonalds_id].group_queue->tail = NULL;
    mcdonalds[mcdonalds_id].group_queue->group_arr = NULL;
}