//
// Created by Administrator on 2023/3/21.
//
class CopyListWithRandom{
public:
    class Node{
    public:
        int val;
        Node* next;
        Node* random;

        explicit Node(int val){
            this->val=val;
            this->next= nullptr;
            this->random= nullptr;
        };
    };

    static Node* copyRandomList(Node* head){
        if(head== nullptr){
            return nullptr;
        }
        Node* cur=head;
        Node* next= nullptr;
        while(cur!= nullptr){
            next=cur->next;
            cur->next=new Node(cur->val);
            cur->next->next=next;
            cur=next;
        }
        cur = head;
        Node* copy = nullptr;
        while(cur!= nullptr){
            next=cur->next->next;
            copy=cur->next;
            copy->random=cur->random== nullptr? nullptr:cur->random->next;
            cur=next;
        }
        Node* res=head->next;
        cur=head;
        while(cur!= nullptr){
            next=cur->next->next;
            copy=cur->next;
            cur->next=next;
            copy->next=next== nullptr? nullptr:next->next;
            cur=next;
        }
        return res;
    }
};