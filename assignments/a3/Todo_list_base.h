// Todo_list_base.h

////////////////////////////////////////////////////////////////////////////
//
// Todo_list_base class
//
////////////////////////////////////////////////////////////////////////////

class Todo_list_base
{
public:
    // destructor
    virtual ~Todo_list_base() {}

	// getters
	virtual int size() const = 0;
	virtual Todo_item get_item(int i) const = 0;

	// setters
	virtual void add_item(const Todo_item& item) = 0;
	virtual void remove_item(int i) = 0;

    // virtual void read_from_file(const string& filename) = 0;

	// printing
	virtual void write_to_file(const string& filename) = 0;
	virtual void write_to_html_file(const string& filename) = 0;

}; // class Todo_list_base
