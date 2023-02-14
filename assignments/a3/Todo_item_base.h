// Todo_item_base.h

////////////////////////////////////////////////////////////////////////////
//
// Todo_item_base class
//
////////////////////////////////////////////////////////////////////////////

// tell the compiler that Todo_item, Date, and string are classes
class Todo_item;

class Todo_item_base
{
public:
	// virtual destructor
	virtual ~Todo_item_base() {}

	// getters
	virtual string get_description() const = 0;
	virtual bool is_done() const = 0;
	virtual Date get_due_date() const = 0;

	// setters
	virtual void set_description(const string& new_description) = 0;
	virtual void set_done() = 0;
	virtual void set_not_done() = 0;
	virtual void set_due_date(const Date& new_due_date) = 0;

	// printing
	// virtual string to_string() const = 0;
	// virtual string to_html_item() const = 0;

}; // class Todo_item_base

bool operator<(const Todo_item& t1, const Todo_item& t2);
