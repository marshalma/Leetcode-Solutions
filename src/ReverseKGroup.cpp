#include<iostream>
#include<vector>

using namespace std;

template<typename T>
std::ostream& operator<<(std::ostream& s, const std::vector<T>& v) {
    s.put('[');
    char comma[3] = {'\0', ' ', '\0'};
    for (const auto& e : v) {
        s << comma << e;
        comma[0] = ',';
    }
    return s << ']';
}


// Definition for singly-linked list.
struct ListNode {
  ListNode(){
    this->next = nullptr;
  }

     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    int numOfNodes(ListNode* head) {
        ListNode* current = head;
        int count = 0;
        while (current != nullptr) {
            count++;
        }
        return count;
    }

    ListNode** getList(ListNode* head, int k) {
        ListNode** result = new ListNode*[k];
        ListNode* current = head;
        result[0] = current;
        for (int i = 1; i < k; i++) {
            current = current->next;
            result[i] = current;
        }
        return result;
    }

    void reorganize(ListNode** list, ListNode* nextHead, int k) {
        for (int i = k-1; i > 0; i--){
            list[i]->next = list[i-1];
        }
        list[0]->next = nextHead;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = numOfNodes(head);
        ListNode* current = head;

        if (count < k) return head;

        // main loop
        ListNode** thisList = getList(current, k);
        ListNode* result = thisList[k-1];
        for (int i = 0; i < count/k - 1; i++) {
            ListNode** nextList = getList(thisList[k-1]->next, k);
            reorganize(thisList, nextList[k-1], k);
            delete[] thisList;
            thisList = nextList;
        }

        if (count % k == 0) {
            reorganize(thisList, nullptr, k);
        }
        else {
            ListNode** tmp = getList(thisList[k-1]->next, 1);
            reorganize(thisList, tmp[0], k);
            delete[] tmp;
        }

        delete[] thisList;
        return result;
    }
};

ListNode* constructLinkList(vector<int> v) {
  ListNode* result = new ListNode;
  ListNode* current = result;
  current->val = v[0];
  for (int i = 1; i < v.size(); i++) {
    ListNode* tmp = new ListNode;
    tmp->val = v[i];
    current->next = tmp;
    current = tmp;
  }
  current->next = nullptr;

  return result;
}

void printLinkList(ListNode* list) {
  ListNode* current = list;
  while(current != nullptr) {
    cout << current->val << ", ";
    current = current->next;
  }

  cout << endl;
}

int main() {
  vector<int> v {1,2,3,4,5};
  cout << v << endl;
  ListNode* test = constructLinkList(v);
  // reverseKGroup(test, 2);
  printLinkList(test);
}
