#ifndef _LRU_INTERFACE_H_
#define _LRU_INTERFACE_H_
#include <iostream>
#include <unordered_map> 

class LruInterface {
  public:
    virtual void SetCapacity(int capacity) = 0;
    virtual int Get(int key) = 0;
    virtual void Put(int key, int value) = 0;
  protect:
    virtual void AddToHead(std::shared_ptr<DLinkedNode>& node) = 0;
    virtual void RemoveNode(std::shared_ptr<DLinkedNode>& node) = 0;
    virtual void MoveToHead(std::shared_ptr<DLinkedNode>& node) = 0;
    virtual std::shared_ptr<DLinkedNode> RemoveTail() = 0;
};

class DLinkedNode {
  public:
    int key_, value_;
    std::shared_ptr<DLinkedNode> prev_;
    std::shared_ptr<DLinkedNode> next_;
    DLinkedNode(): key_(0), value_(0), prev_(nullptr), next_(nullptr) {}
    DLinkedNode(int key, int value): key_(key), value_(value), prev_(nullptr), next_(nullptr) {}
};

class LinkLru : public LruInterface{
  public:
    virtual void SetCapacity(int capacity) override;
    virtual int get(int key) override;
    virtual void put(int key, int value) override;
  protect:
    virtual void AddToHead(std::shared_ptr<DLinkedNode>& node) override;
    virtual void RemoveNode(std::shared_ptr<DLinkedNode>& node) override;
    virtual void MoveToHead(std::shared_ptr<DLinkedNode>& node) override;
    virtual std::shared_ptr<DLinkedNode> RemoveTail() override;
  private:
    int capacity_;
    std::shared_ptr<DLinkedNode> head_;
    std::shared_ptr<DLinkedNode> tail_;
    std::unordered_map<int, std::shared_ptr<DLinkedNode>> cache_;
};
#endif