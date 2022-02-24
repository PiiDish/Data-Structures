//	Stack Node
//	Author Name: Jason Disher
//	Student No: c3185333
//	Last Modified: 24/2/2022


public class Node<E>
{
	private E payload;
	private Node<E> next;
	

		//Constructor
	public Node()
	{
		payload=null;
		next=null;
	}
	public Node(E data)
	{
		payload=data;
		next=null;
	}
		//Mutators
	public void setNext(Node<E> node)
	{
		next=node;
	}
	public void setPayload(E data)
	{
		payload=data;
	}
		//Queries
	public E getPayload()
	{
		return payload;
	}
	public Node<E> next()
	{
		return next;
	}
}