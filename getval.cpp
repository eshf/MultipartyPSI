EM_JS(void, log_value, (EM_VAL val_handle), {
    let value = Emval.toValue(val_handle);
    console.log(value);
  });
  
  EM_JS(EM_VAL, find_myinput, (), {
    let input = document.getElementById('myinput');
    return Emval.toHandle(input);
  });
  
  val obj = val::object();
  obj.set("x", 1);
  obj.set("y", 2);
  log_value(obj.as_handle()); // logs { x: 1, y: 2 }
  
  val myinput = val::take_ownership(find_input());
  // Now you can store the `find_myinput` DOM element for as long as you like, and access it later like:
  std::string value = input["value"].as<std::string>();