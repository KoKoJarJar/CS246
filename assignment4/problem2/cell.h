class Cell {
public:
  virtual State state() = 0;
  virtual void update(State state) = 0;
  virtual void add_publisher(const std::unique_ptr<Publisher> publisher) = 0;
  virtual ~Cell(){};
};
