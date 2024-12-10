 // void deleteAtHead(int val)
    // {
    //     if (head == NULL)
    //     {
    //         cout << "List is empty" << endl;
    //     }
    //     else if (head->data == val)
    //     {
    //         Node *temp = head;
    //         head = head->next;
    //         delete temp;
    //     }
    //     else
    //     {
    //         Node *h = head;
    //         while (h->next != NULL && h->next->data != val)
    //         {
    //             h = h->next;
    //         }
    //         if (h->next == NULL)
    //         {
    //             cout << "Roll no not found" << endl;
    //         }
    //         else
    //         {
    //             Node *temp = h->next;
    //             h->next = h->next->next;
    //             delete temp;
    //         }
    //     }
    // }