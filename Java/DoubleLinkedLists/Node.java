//	Double Linked List Node Class
//	Author Name: Jason Disher
//	Student No: c3185333
//	Last Modified: 24/2/2022


public class Node<E>
{
		// Private member varaibles
	private Node<E> next;
	private Node<E> previous;
	private E payload;

		// Constuctors
	public Node()
	{
		next=null;
		previous=null;
		payload=null;
	}
	public Node(E data)
	{
		next=null;
		previous=null;
		payload=data;
	}
	public Node(Node<E> nxt, Node<E> prev, E data)
	{
		next=nxt;
		previous=prev;
		payload=data;
	}
		//Mutators
	public void setNext(Node<E> nxt)
	{
		next=nxt;
	}
	public void setPrevious(Node<E> prev)
	{
		previous=prev;
	}
	public void setPayload(E data)
	{
		payload=data;
	}
		// Queries
	public Node<E> next()
	{
		return next;
	}
	public Node<E> previous()
	{
		return previous;
	}
	public E getPayload()
	{
		return payload;
	}

}