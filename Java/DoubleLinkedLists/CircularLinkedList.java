//	Circular Linked List Class
//	Author Name: Jason Disher
//	Student No: c3185333
//	Last Modified: 24/2/2022


public class CircularLinkedList<E>
{
	private Node<E> sentinel;
	private Node<E> itr;
	private Integer count;

		// Constructors
	public CircularLinkedList()
	{
		sentinel = new Node<E>();
		itr=sentinel;
		count=0;
	}
	public CircularLinkedList(Node<E> node)
	{
		sentinel = new Node<E>();

		sentinel.setNext(node);
		sentinel.setPrevious(node);
		node.setNext(sentinel);
		node.setPrevious(sentinel);
		itr=sentinel;
		count=1;
	}
		// Mutators
	public void prepend(E data)
	{
		Node<E> new_node = new Node<E>(data);

		if(count==0)
		{
			sentinel.setNext(new_node);
			sentinel.setPrevious(new_node);
			new_node.setNext(sentinel);
			new_node.setPrevious(sentinel);
		}
		else
		{
			new_node.setNext(sentinel.next());
			new_node.setPrevious(sentinel);
			sentinel.setNext(new_node);
		}

		count++;
	}
	public void append(E data)
	{
		Node<E> new_node = new Node<E>(data);

		if(count==0)
		{
			sentinel.setNext(new_node);
			sentinel.setPrevious(new_node);
			new_node.setNext(sentinel);
			new_node.setPrevious(sentinel);
		}

		else
		{
			new_node.setNext(sentinel.previous());
			new_node.setPrevious(sentinel.next());
			sentinel.setPrevious(new_node);
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

		itr=sentinel;
		count++;
	}
	public E removeHead()
	{
		E tmp;
		itr=sentinel;

		if(count != 0)
		{
			itr=sentinel.next();
			sentinel.setNext(itr.next());

			tmp = itr.getPayload();
			itr = sentinel;
		}
		else
			return null;

		count--;

		return tmp;
	}
	public E removeTail()
	{
		E tmp;
		itr=sentinel;

		if(count != 0)
		{
			itr=sentinel.previous();
			sentinel.setPrevious(itr.previous());

			tmp = itr.getPayload();
			itr = sentinel;
		}
		else
			return null;

		count--;

		return tmp;
	}
	public E remove()
	{
		E tmp = itr.getPayload();//=itr.next();
		//Node<E> prev=itr.previous();

		itr.previous().setNext(itr.next());
		itr.next().setPrevious(itr.previous());

		count--;

		return tmp; //itr.getPayload();
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
		itr=sentinel.next();
	}
	public void goTail()
	{
		itr=sentinel.previous();
	}
		// Queries
	public E peek()
	{
		if(count != 0)
			return sentinel.next().getPayload();
		else
			return null;
	}
	public E peekTail()
	{
		if(count != 0)
			return sentinel.previous().getPayload();
		else
			return null;
	}
	public Integer size()
	{
		return count;
	}
	public Boolean isEmpty()
	{
		return count==0;
	}
	public void reset()
	{
		itr = senteniel;
	}
}
