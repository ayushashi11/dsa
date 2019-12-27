class List_Node{
    constructor(data,x=0,y=0,next=null){
        this.data = data;
        this.x = x;
        this.y = y;
        this.next = next;
    }
    setpos(x=0,y=0){
        this.x=x;
        this.y=y;
    }
    getpos(){
        return [this.x,this.y];
    }
}
class Circular_Linked_List{
    constructor(head=null){
        this.head = head;
        this.tail = head;
        if(head != null){
            this.head.next = this.head;
        }
        this._endx = 0;
        this._y = 10;
    }
    add(data){
        var curr = new List_Node(data, this._endx, this._y);
        if(this.head == null){
            curr.next = curr;
            this.head = curr;
            this.tail = curr;
            return;
        }
        curr.next = this.head;
        this.tail.next = curr;
        this.tail = curr;
        this._endx += 20;
    }
    add_node(curr){
        curr.setpos(this._endx,this._y);
        if(this.head == null){
            curr.next = curr;
            this.head = curr;
            this.tail = curr;
            return;
        }
        curr.next = this.head;
        this.tail.next = curr;
        this.tail = curr;
        this._endx += 20;
    }
}