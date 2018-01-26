class Publisher {
public:
  virtual void publish(State &prev_state, State &curr_state) = 0;
  ~Publisher(){};
};
