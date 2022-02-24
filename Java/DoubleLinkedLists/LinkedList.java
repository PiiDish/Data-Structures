//	Double Linked List Class
//	Author Name: Jason Disher
//	Student No: c3185333
//	Last Modified: 9/3/2019


public class LinkedList<E> implements Deque<E>
{
	private Node<E> head;
	private Node<E> tail;
	private Node<E> itr;
	private Integer count;

		// Constructors
	public LinkedList()
	{
		head=null;
		tail=null;
		itr=head;
		count=0;
	}
	public LinkedList(Node<E> node)
	{
		head=node;
		tail=node;
		itr=head;
		count=1;
	}
		// Mutators
	public void prepend(E data)
	{
		Node<E> new_node = new Node<E>(data);

		if(count==0)
		{
			head=new_node;
			tail=head;
		}
		if(head!=null)
		{
			head.setPrevious(new_node);
			new_node.setNext(head);
			head=new_node;
		}
		count++;
	}
	public void append(E data)
	{
		Node<E> new_node = new Node<E>(data);

		if(count==0)
		{
			tail=new_node;
			head=tail;
		}

		if(tail!=null)
		{
			tail.setNext(new_node);
			new_node.setPrevious(tail);
			tail=new_node;
		}
		count++;
	}
	public void insert(E data)
	{
		Node<E> new_node = new Node<E>(data);

		new_node.setNext(itr);
		new_node.setPrevious(itr.previous());
		itr.previous().setNext(new_node);
		itr.setPrevious(new_node);
		itr=head;
		count++;
	}
	public E removeHead()
	{
		itr=head;
		if(head.next()!=null)
			head=head.next();
		count--;

		return itr.getPayload();
	}
	public E removeTail()
	{
		itr=tail;
		tail=tail.previous();
		count--;

		return itr.getPayload();
	}
	public E remove()
	{
		Node<E> nxt=itr.next();
		Node<E> prev=itr.previous();

		nxt.setPrevious(prev);
		prev.setNext(nxt);
		count--;

		return itr.getPayload();
	}
		// Memeber methods
	public void fwd()
	{
		itr=itr.next();
	}
	public void back()
	{
		itr=itr.previous();
	}
	public void goHead()
	{
		itr=head;
	}
	public void goTail()
	{
		itr=tail;
	}
		// Queries
	public E peek()
	{
		return itr.getPayload();
	}
	public E peekHead()
	{
		return head.getPayload();
	}
	public E peekTail()
	{
		return tail.getPayload();
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