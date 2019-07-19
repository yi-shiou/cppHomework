
#include <iostream>
struct List
{
    int val;
    List* next = NULL;
};

List* del(List* l, int i) {
    List* current = l;
    int index = 0;
    if (l == NULL) return l;
    if (i == 0) {
        l = current->next;
        std::cout << current << " ";
        delete current;
        return l;
    }
    while (index < i - 1 && current != NULL) {
        index++;
        current = current->next;
    }//index == i - 1;
    List* swap = current->next->next;
    delete current->next;
    current->next = swap;
    return l;
}

void del2(List* l, int i) {
    List* current = l;
    int index = 0;
    if (l == NULL) return;
    if (i == 0) {
        l = current->next;//**************** 要怎摸改?
        std::cout << current << " ";
        delete current;
        return;
    }
    while (index < i - 1 && current != NULL) {
        index++;
        current = current->next;
    }//index == i - 1;
    List* swap = current->next->next;
    delete current->next;
    current->next = swap;
}

int main()
{
    List* l = new List;
    List* current;
    int nums[] = { 1,2,3,4,5 };

    //add array to list
    l->val = nums[0];
    current = l;
    for (int i = 1; i < sizeof(nums)/sizeof(nums[0]); i++)
    {
        if (current->next == NULL) {
            current->next = new List;
            current = current->next;
        }
        current->val = nums[i];
    }

    // delete element
    //l = del(l, 0);
    del2(l, 0); 


    // print
    current = l;
    while (current != NULL)
    {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << "\n";

    // delete List
    current = l;
    List* tmp;
    while (current != NULL)
    {
        tmp = current;
        std::cout << current->val << "bye ";
        current = current->next;
        delete tmp;
    }
    std::cout << "\n";

    return 0;
}
