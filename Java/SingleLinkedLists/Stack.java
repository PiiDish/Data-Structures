//	Stack Class
//	Author Name: Jason Disher
//	Student No: c3185333
//	Last Modified: 24/2/2022


public class Stack<E>
{
	Node<E> top;
	int count;

		//Constructor
	public Stack()
	{
		top=null;
		count=0;
	}
	public Stack(Node<E> obj)
	{
		top=obj;
		count=1;
	}
		//Mutators
	public void push(E obj)
	{
		Node<E> new_node = new Node<E>(obj);
		new_node.setNext(top);
		top=new_node;
		count++; 
	}
	public E pop()
	{
		Node<E> temp;
		temp=top;
		top=temp.next();
		count--;
		return temp.getPayload();
	}
		//Queries
	public E peek()
	{
		return top.getPayload();
	}
	public Integer size()
	{
		return count;
	}
	public Boolean isEmpty()
	{
		return count==0;
	}
}