#pragma once
#pragma once

template <typename T>
struct link
{
	T value;
	link *next;
};

template <typename T>
class list;
template <typename T>
class iterator;
template <typename T>
class const_iterator;

template <typename T>
class iterator
{
	friend class const_iterator<T>;
	friend class list<T>;

	link<T> *pred;
	link<T> *curr;
public:
	iterator() : pred(nullptr), curr(nullptr) {}
	iterator(const iterator &obj) { pred = obj.pred; curr = obj.curr; }
	iterator(const const_iterator<T> &obj) { pred = obj.pred; curr = obj.curr; }

	iterator& operator=(const iterator& rhs) { pred = rhs.pred; curr = rhs.curr; return *this; }
	iterator& operator++() { pred = curr; curr = curr->next; return *this; }
	iterator operator++(int) { iterator temp(*this); ++(*this); return temp; }

	bool operator==(const iterator &rhs) const { return curr == rhs.curr; }
	bool operator!=(const iterator &rhs) const { return !(*this == rhs); }

	T& operator*() { return curr->value; }
	T* operator->() { return &(curr->value); }
};

template <typename T>
class const_iterator
{
	friend class iterator<T>;
	friend class list<T>;

	link<T> *pred;
	link<T> *curr;
public:
	const_iterator() : pred(nullptr), curr(nullptr) {}
	const_iterator(const iterator<T> &obj) { pred = obj.pred; curr = obj.curr; }
	const_iterator(const const_iterator &obj) { pred = obj.pred; curr = obj.curr; }

	const_iterator& operator=(const const_iterator& rhs) { pred = rhs.pred; curr = rhs.curr; return *this; }
	const_iterator& operator++() { pred = curr; curr = curr->next; return *this; }
	const_iterator operator++(int) { const_iterator temp(*this); ++(*this); return temp; }

	bool operator==(const const_iterator &rhs) const { return curr == rhs.curr; }
	bool operator!=(const const_iterator &rhs) const { return !(this->operator==(rhs)); }

	T const& operator*() const { return curr->value; }
	T const* operator->() const { return &(curr->value); }
};

template <typename T>
class list
{
	friend class iterator<T>;
	friend class const_iterator<T>;
public:
	typedef iterator<T> iterator;
	typedef const_iterator<T> const_iterator;
private:
	link<T> *head;
	link<T> *last;
public:
	list() : head(nullptr), last(nullptr) {}
	list(const list &obj);
	list(const T &_value);
	~list();
	list& operator=(const list &rhs);

	void push_back(const T &_value);
	void pop_back();
	void push_front(const T &_value);
	void pop_front();

	iterator insert(const_iterator iter, const T &_value);
	iterator erase(const_iterator iter);
	iterator begin() const;
	iterator end() const;

	const_iterator cbegin() const;
	const_iterator cend() const;
};

template <typename T>
list<T>::list(const list &obj)
{
	head = new link<T>;
	head->value = obj.head->value;
	link<T> *p = obj.head->next;
	link<T> *q = head;
	while (p)
	{
		q->next = new link<T>;
		q = q->next;
		q->value = p->value;
		p = p->next;
	}
	q->next = nullptr;
	last = q;
}

template <typename T>
list<T>::list(const T &_value)
{
	head = new link<T>;
	head->value = _value;
	head->next = nullptr;
	last = head;
}

template <typename T>
list<T>::~list()
{
	link<T> *p = head;
	link<T> *q = head;
	while (p)
	{
		q = p;
		p = p->next;
		delete q;
	}
	head = nullptr;
}

template <typename T>
list<T>& list<T>::operator=(const list &rhs)
{
	if (this == &rhs) return *this;
	link<T> *p = head;
	link<T> *q = head;
	while (p)
	{
		q = p;
		p = p->next;
		delete q;
	}
	head = new link<T>;
	head->value = rhs.head->value;
	p = rhs.head->next;
	q = head;
	while (p)
	{
		q->next = new link<T>;
		q = q->next;
		q->value = p->value;
		p = p->next;
	}
	q->next = nullptr;
	last = q;
	return *this;
}

template <typename T>
void list<T>::push_back(const T &_value)
{
	if (!head)
	{
		push_front(_value);
		return;
	}
	link<T> *p = last;
	p->next = new link<T>;
	p = p->next;
	p->value = _value;
	p->next = nullptr;
	last = p;
}

template <typename T>
void list<T>::pop_back()
{
	if (!head) throw "list is empty";
	if (head == last)
	{
		delete head;
		head = last = nullptr;
		return;
	}
	link<T> *p = head;
	while (p->next->next)
	{
		p = p->next;
	}
	delete p->next;
	p->next = nullptr;
	last = p;
}

template <typename T>
void list<T>::push_front(const T &_value)
{
	link<T> *p = new link<T>;
	p->value = _value;
	p->next = head;
	head = p;
	if (!last)
	{
		last = head;
	}
}

template <typename T>
void list<T>::pop_front()
{
	if (!head) throw "list is empty";
	if (head == last)
	{
		delete head;
		head = last = nullptr;
		return;
	}
	link<T> *p = head;
	head = head->next;
	delete p;
}

template <typename T>
iterator<T> list<T>::insert(const_iterator iter, const T &_value)
{
	if (iter.curr == head)
	{
		push_front(_value);
		return iterator();
	}
	link<T> *p = new link<T>;
	p->value = _value;
	p->next = iter.curr;
	iter.pred->next = p;
	iter.curr = p;
	return iter;
}

template <typename T>
iterator<T> list<T>::erase(const_iterator iter)
{
	if (iter.curr == head)
	{
		pop_front();
		return iterator();
	}
	if (iter.curr == nullptr)
	{
		pop_back();
		return end();
	}
	link<T> *p = iter.curr;
	iter.curr = iter.curr->next;
	iter.pred->next = iter.curr;
	delete p;
	return iter;
}

template <typename T>
iterator<T> list<T>::begin() const
{
	iterator iter;
	iter.pred = nullptr;
	iter.curr = head;
	return iter;
}

template <typename T>
iterator<T> list<T>::end() const
{
	iterator iter;
	iter.pred = last;
	iter.curr = nullptr;
	return iter;
}

template <typename T>
const_iterator<T> list<T>::cbegin() const
{
	const_iterator citer;
	citer.pred = nullptr;
	citer.curr = head;
	return citer;
}

template <typename T>
const_iterator<T> list<T>::cend() const
{
	const_iterator citer;
	citer.pred = last;
	citer.curr = nullptr;
	return citer;
}