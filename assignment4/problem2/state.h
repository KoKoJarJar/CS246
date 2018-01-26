class State {
public:
  virtual unsigned int get_value() = 0;
  virtual unsigned int set_value(unsigned int input) = 0;
  virtual ~State(){};
};
