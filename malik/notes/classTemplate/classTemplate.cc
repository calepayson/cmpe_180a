template <class elemType>
class listType {
   public:
    bool isEmpty() const;
    bool isFull() const;
    void search(const elemType &searchItem, bool &found) const;
    void insert(const elemType &newElement);
    void remove(const elemType &removeElement);
    void destroyList();
    void printList() const;

   private:
    elemType list[100];
    int length;
};
