#include "lru.h"

void LinkLru::SetCapacity(int capacity) {
    capacity_ = capacity;
}

void LinkLru::AddToHead(std::shared_ptr<DLinkedNode>& node) {
    node->prev_ = head_;
    node->next_ = head_->next_;
    head_->next_->prev_ = node;
    head_->next_ = node;
}

void LinkLru::RemoveNode(std::shared_ptr<DLinkedNode>& node) {
    node->prev_->next_ = node->next_;
    node->next_->prev_ = node->prev_;
}

void LinkLru::MoveToHead(std::shared_ptr<DLinkedNode>& node) {
    RemoveNode(node);
    AddToHead(node);
}

std::shared_ptr<DLinkedNode> LinkLru::RemoveTail() {
    std::shared_ptr<DLinkedNode> node = tail_->prev_;
    RemoveNode(node_);
}

int LinkLru::get(int key) {
    if(!cache_.count(key)) {
        return -1;
    }
    std::shared_ptr<DLinkedNode> node = cache_[key];
    MoveToHead(node);
    return node->value;
}