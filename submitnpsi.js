  let obj = Emval.fromHandle($0);
  console.log(obj);
  obj.as_handle();

  mergeInto(LibraryManager.library, {
  log_value: function (val_handle) {
  let value = Emval.toValue(val_handle);
  console.log(value);
  }
});