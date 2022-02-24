//	Linked List Interface -- Deque --
//	Aurthor Name: Jason Disher
//	Student No: c3185333
//	Last Modified: 24/2/2022


public interface Deque<E>
{
	public void append(E data);
	public void prepend(E data);
	public E removeHead();
	public E removeTail();
	public E peekHead();
	public E peekTail();
	public Boolean isEmpty();
}