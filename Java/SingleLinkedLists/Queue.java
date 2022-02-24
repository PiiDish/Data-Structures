//	Queue Class
//	Author Name: Jason Disher
//	Student No: C3185333
//	lAST modified: 24/2/2022


public class Queue<E>
{
	private Node<E> head;
	private Node<E> tail;
	int count;

	public Queue()
	{
		head=null;
		tail=null;
		count=0;
	}
	public Queue(E obj)
	{
		Node<E> new_node = new Node<E>(obj);
		head=new_node;
		head.setNext(tail);
		count++;
	} 
		//Mutators
	public void enqueue(E obj)
	{
		Node<E> new_node = new Node<E>(obj);

		if(head==null)
		{
			head=new_node;
			
		}
		else if(tail==null)
		{
			tail=new_node;
			head.setNext(tail);
		}
		else
		{
			tail.setNext(new_node);
			tail=new_node;
		}
		count++;
	}
	public E dequeue()
	{
		if(head!=null)
		{
			E temp=head.getPayload();
	
			head=head.next();
			count--;
		}
		return temp;
	}
		//Queries
	public E peek()
	{
		return head.getPayload();
	}
	public int size()
	{
		return count;
	}
	public Boolean isEmpty()
	{
		return count==0;
	}

}