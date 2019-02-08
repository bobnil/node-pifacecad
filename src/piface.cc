#include <node.h>
#include <v8.h>
#include <nan.h>
#include <pifacecad.h>

#include <iostream>

using namespace v8;

const char* ToCString(const String::Utf8Value &value){
	return *value ? *value : "str fail";
}

void pifacecad_open(const FunctionCallbackInfo<Value> &args){
	args.GetReturnValue().Set(pifacecad_open());
}

void pifacecad_open_noinit(const FunctionCallbackInfo<Value> &args){
	args.GetReturnValue().Set(pifacecad_open_noinit());
}

void pifacecad_close(const FunctionCallbackInfo<Value> &args){
	pifacecad_close();
	args.GetReturnValue().SetNull();
}

void pifacecad_lcd_init (const FunctionCallbackInfo<Value> &args){
	pifacecad_lcd_init();
	args.GetReturnValue().SetNull();
}

void pifacecad_read_switches(const FunctionCallbackInfo<Value> &args){
	args.GetReturnValue().Set(pifacecad_read_switches());
}

void pifacecad_read_switch(const FunctionCallbackInfo<Value> &args){
	Isolate *isolate = args.GetIsolate();
	if(args.Length()!=1){
		isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}
	if(!args[0]->IsNumber()){
		isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "wrong arguments")));
		return;
	}
	args.GetReturnValue().Set( Number::New( isolate, pifacecad_read_switch(
    args[0]->NumberValue(Nan::GetCurrentContext()).ToChecked()
  )));
}

void pifacecad_lcd_write(const FunctionCallbackInfo<Value> &args){
	Isolate *isolate = args.GetIsolate();
	if(args.Length()!=1){
		isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong string of arguments")));
		return;
	}
	if(!args[0]->IsString()){
		isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "wrong arguments")));
		return;
	}
  Nan::Utf8String test( args[0]->ToString(Nan::GetCurrentContext()).ToLocalChecked());
	//args.GetReturnValue().Set(Number::New(isolate, pifacecad_lcd_write(ToCString(test))));
	args.GetReturnValue().Set(Number::New(isolate, pifacecad_lcd_write(*test)));
}

void pifacecad_lcd_set_cursor(const FunctionCallbackInfo<Value> &args){
	Isolate *isolate = args.GetIsolate();
	if(args.Length()!=2){
		isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}
	if(!args[0]->IsNumber() || !args[1]->IsNumber()){
		isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "wrong arguments")));
		return;
	}
	args.GetReturnValue().Set(Number::New(isolate, pifacecad_lcd_set_cursor(
    args[0]->NumberValue(Nan::GetCurrentContext()).ToChecked(),
    args[1]->NumberValue(Nan::GetCurrentContext()).ToChecked()
  )));
}

void pifacecad_lcd_set_cursor_address(const FunctionCallbackInfo<Value> &args){
	Isolate *isolate = args.GetIsolate();
	if(args.Length()!=1){
		isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}
	if(!args[0]->IsNumber()){
		isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "wrong arguments")));
		return;
	}
	pifacecad_lcd_set_cursor_address(
    args[0]->NumberValue(Nan::GetCurrentContext()).ToChecked()
  );
	args.GetReturnValue().SetNull();
}

void pifacecad_lcd_get_cursor_address(const FunctionCallbackInfo<Value> &args){
	args.GetReturnValue().Set(pifacecad_lcd_get_cursor_address());
}

void pifacecad_lcd_clear (const FunctionCallbackInfo<Value> &args){
	pifacecad_lcd_clear();
	args.GetReturnValue().SetNull();
}

void pifacecad_lcd_home (const FunctionCallbackInfo<Value> &args){
	pifacecad_lcd_home();
	args.GetReturnValue().SetNull();
}

void pifacecad_lcd_display (const FunctionCallbackInfo<Value> &args){
	Isolate* isolate = args.GetIsolate();
	if(args.Length() != 1){
		isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "wrong number of arguments")));
		return;
	}
	if(!args[0]->IsNumber()){
	//if(!args[0]->IsBoolean()){
		isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "wrong arguments")));
		return;
	}
	pifacecad_lcd_display(args[0]->NumberValue(Nan::GetCurrentContext()).ToChecked());
	args.GetReturnValue().SetNull();
}

void pifacecad_lcd_blink (const FunctionCallbackInfo<Value> &args){
	args.GetReturnValue().SetNull();
}
void pifacecad_lcd_cursor (const FunctionCallbackInfo<Value> &args){
	args.GetReturnValue().SetNull();
}
void pifacecad_lcd_autoscroll (const FunctionCallbackInfo<Value> &args){
	args.GetReturnValue().SetNull();
}

void pifacecad_lcd_display_on (const FunctionCallbackInfo<Value> &args){
	pifacecad_lcd_display_on();
	args.GetReturnValue().SetNull();
}

void pifacecad_lcd_display_off (const FunctionCallbackInfo<Value> &args){
	pifacecad_lcd_display_off();
	args.GetReturnValue().SetNull();
}

void pifacecad_lcd_blink_on (const FunctionCallbackInfo<Value> &args){
	pifacecad_lcd_blink_on();
	args.GetReturnValue().SetNull();
}

void pifacecad_lcd_blink_off (const FunctionCallbackInfo<Value> &args){
	pifacecad_lcd_blink_off();
	args.GetReturnValue().SetNull();
}

void pifacecad_lcd_cursor_on (const FunctionCallbackInfo<Value> &args){
	pifacecad_lcd_cursor_on();
	args.GetReturnValue().SetNull();
}

void pifacecad_lcd_cursor_off (const FunctionCallbackInfo<Value> &args){
	pifacecad_lcd_cursor_off();
	args.GetReturnValue().SetNull();
}

void pifacecad_lcd_backlight_on(const FunctionCallbackInfo<Value> &args){
	pifacecad_lcd_backlight_on();
	args.GetReturnValue().SetNull();
}

void pifacecad_lcd_backlight_off(const FunctionCallbackInfo<Value> &args){
	pifacecad_lcd_backlight_off();
	args.GetReturnValue().SetNull();
}

void pifacecad_lcd_move_left(const FunctionCallbackInfo<Value> &args){
	pifacecad_lcd_move_left();
	args.GetReturnValue().SetNull();
}

void pifacecad_lcd_move_right(const FunctionCallbackInfo<Value> &args){
	pifacecad_lcd_move_right();
	args.GetReturnValue().SetNull();
}

void pifacecad_lcd_left_to_right(const FunctionCallbackInfo<Value> &args){
	pifacecad_lcd_left_to_right();
	args.GetReturnValue().SetNull();
}

void pifacecad_lcd_right_to_left(const FunctionCallbackInfo<Value> &args){
	pifacecad_lcd_right_to_left();
	args.GetReturnValue().SetNull();
}

void pifacecad_lcd_autoscroll_on(const FunctionCallbackInfo<Value> &args){
	pifacecad_lcd_autoscroll_on();
	args.GetReturnValue().SetNull();
}

void pifacecad_lcd_autoscroll_off(const FunctionCallbackInfo<Value> &args){
	pifacecad_lcd_autoscroll_off();
	args.GetReturnValue().SetNull();
}

void pifacecad_lcd_write_custom_bitmap(const FunctionCallbackInfo<Value> &args){
	Isolate* isolate = args.GetIsolate();
	if(args.Length() != 1){
		isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "wrong number of arguments")));
		return;
	}
	if(!args[0]->IsNumber()){
		isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "wrong arguments")));
		return;
	}
	pifacecad_lcd_write_custom_bitmap(
    args[0]->NumberValue(Nan::GetCurrentContext()).ToChecked()
  );
	args.GetReturnValue().SetNull();
}

void pifacecad_lcd_store_custom_bitmap(const FunctionCallbackInfo<Value> &args){
	Isolate* isolate = args.GetIsolate();
	if(args.Length() != 2){
		isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "wrong number of arguments")));
		return;
	}
	if(!args[0]->IsNumber() || !args[1]->IsArray()){
		isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "wrong arguments")));
		return;
	}
	Local<Array> bitmap = Local<Array>::Cast(args[1]);
	unsigned int bitmapLength = bitmap->Length();
	unsigned char *arr = new unsigned char[bitmapLength];
	for(unsigned int i=0; i<bitmapLength; i++){
		arr[i] = bitmap->Get(i)->NumberValue(Nan::GetCurrentContext()).ToChecked();
	}
	pifacecad_lcd_store_custom_bitmap(
    args[0]->NumberValue(Nan::GetCurrentContext()).ToChecked(),
    arr
  );
	args.GetReturnValue().SetNull();
	delete[] arr;
}

void pifacecad_lcd_send_command(const FunctionCallbackInfo<Value> &args){
	Isolate* isolate = args.GetIsolate();
	if(args.Length() != 1){
		isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "wrong number of arguments")));
		return;
	}
	if(!args[0]->IsNumber()){
		isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "wrong arguments")));
		return;
	}
	pifacecad_lcd_send_command(args[0]->NumberValue(Nan::GetCurrentContext()).ToChecked());
	args.GetReturnValue().SetNull();
}

void pifacecad_lcd_send_data(const FunctionCallbackInfo<Value> &args){
	Isolate* isolate = args.GetIsolate();
	if(args.Length() != 1){
		isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "wrong number of arguments")));
		return;
	}
	if(!args[0]->IsNumber()){
		isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "wrong arguments")));
		return;
	}
	pifacecad_lcd_send_data(args[0]->NumberValue(Nan::GetCurrentContext()).ToChecked());
	args.GetReturnValue().SetNull();
}

void pifacecad_lcd_send_byte(const FunctionCallbackInfo<Value> &args){
	Isolate* isolate = args.GetIsolate();
	if(args.Length() != 1){
		isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "wrong number of arguments")));
		return;
	}
	if(!args[0]->IsNumber()){
		isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "wrong arguments")));
		return;
	}
	pifacecad_lcd_send_byte(args[0]->NumberValue(Nan::GetCurrentContext()).ToChecked());
	args.GetReturnValue().SetNull();
}

void pifacecad_lcd_set_rs(const FunctionCallbackInfo<Value> &args){
	Isolate* isolate = args.GetIsolate();
	if(args.Length() != 1){
		isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "wrong number of arguments")));
		return;
	}
	if(!args[0]->IsNumber()){
		isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "wrong arguments")));
		return;
	}
	pifacecad_lcd_set_rs(args[0]->NumberValue(Nan::GetCurrentContext()).ToChecked());
	args.GetReturnValue().SetNull();
}

void pifacecad_lcd_set_rw(const FunctionCallbackInfo<Value> &args){
	Isolate* isolate = args.GetIsolate();
	if(args.Length() != 1){
		isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "wrong number of arguments")));
		return;
	}
	if(!args[0]->IsNumber()){
		isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "wrong arguments")));
		return;
	}
	pifacecad_lcd_set_rw(args[0]->NumberValue(Nan::GetCurrentContext()).ToChecked());
	args.GetReturnValue().SetNull();
}

void pifacecad_lcd_set_enable(const FunctionCallbackInfo<Value> &args){
	Isolate* isolate = args.GetIsolate();
	if(args.Length() != 1){
		isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "wrong number of arguments")));
		return;
	}
	if(!args[0]->IsNumber()){
		isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "wrong arguments")));
		return;
	}
	pifacecad_lcd_set_enable(args[0]->NumberValue(Nan::GetCurrentContext()).ToChecked());
	args.GetReturnValue().SetNull();
}

void pifacecad_lcd_set_backlight(const FunctionCallbackInfo<Value> &args){
	Isolate* isolate = args.GetIsolate();
	if(args.Length() != 1){
		isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "wrong number of arguments")));
		return;
	}
	if(!args[0]->IsNumber()){
		isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "wrong arguments")));
		return;
	}
	pifacecad_lcd_set_backlight(args[0]->NumberValue(Nan::GetCurrentContext()).ToChecked());
	args.GetReturnValue().SetNull();
}

void pifacecad_lcd_pulse_enable(const FunctionCallbackInfo<Value> &args){
	pifacecad_lcd_pulse_enable();
	args.GetReturnValue().SetNull();
}

void colrow2address(const FunctionCallbackInfo<Value> &args){
	Isolate* isolate = args.GetIsolate();
	if(args.Length() != 2){
		isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "wrong number of arguments")));
		return;
	}
	if(!args[0]->IsNumber() || !args[1]->IsNumber()){
		isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "wrong arguments")));
		return;
	}
	args.GetReturnValue().Set(Number::New(isolate, colrow2address(
    args[0]->NumberValue(Nan::GetCurrentContext()).ToChecked(),
    args[1]->NumberValue(Nan::GetCurrentContext()).ToChecked()
  )));
}

void address2col(const FunctionCallbackInfo<Value> &args){
	Isolate* isolate = args.GetIsolate();
	if(args.Length() != 1){
		isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "wrong number of arguments")));
		return;
	}
	if(!args[0]->IsNumber()){
		isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "wrong arguments")));
		return;
	}
	args.GetReturnValue().Set(Number::New(isolate, address2col(
    args[0]->NumberValue(Nan::GetCurrentContext()).ToChecked()
  )));
}

void Init(Local<Object> exports){
	NODE_SET_METHOD(exports, "open", pifacecad_open);
	NODE_SET_METHOD(exports, "open_noinit", pifacecad_open_noinit);
	NODE_SET_METHOD(exports, "close", pifacecad_close);
	NODE_SET_METHOD(exports, "lcd_init", pifacecad_lcd_init);
	NODE_SET_METHOD(exports, "read_switches", pifacecad_read_switches);
	NODE_SET_METHOD(exports, "read_switch", pifacecad_read_switch);
	NODE_SET_METHOD(exports, "lcd_write", pifacecad_lcd_write);
	NODE_SET_METHOD(exports, "lcd_set_cursor", pifacecad_lcd_set_cursor);
	NODE_SET_METHOD(exports, "lcd_set_cursor_address", pifacecad_lcd_set_cursor_address);
	NODE_SET_METHOD(exports, "lcd_get_cursor_address", pifacecad_lcd_get_cursor_address);
	NODE_SET_METHOD(exports, "lcd_clear", pifacecad_lcd_clear);
	NODE_SET_METHOD(exports, "lcd_home", pifacecad_lcd_home);
	NODE_SET_METHOD(exports, "lcd_display", pifacecad_lcd_display);
	NODE_SET_METHOD(exports, "lcd_display_on", pifacecad_lcd_display_on);
	NODE_SET_METHOD(exports, "lcd_display_off", pifacecad_lcd_display_off);
	NODE_SET_METHOD(exports, "lcd_blink", pifacecad_lcd_blink);
	NODE_SET_METHOD(exports, "lcd_blink_on", pifacecad_lcd_blink_on);
	NODE_SET_METHOD(exports, "lcd_blink_off", pifacecad_lcd_blink_off);
	NODE_SET_METHOD(exports, "lcd_cursor", pifacecad_lcd_cursor);
	NODE_SET_METHOD(exports, "lcd_cursor_on", pifacecad_lcd_cursor_on);
	NODE_SET_METHOD(exports, "lcd_cursor_off", pifacecad_lcd_cursor_off);
	NODE_SET_METHOD(exports, "lcd_backlight_on", pifacecad_lcd_backlight_on);
	NODE_SET_METHOD(exports, "lcd_backlight_off", pifacecad_lcd_backlight_off);
	NODE_SET_METHOD(exports, "lcd_move_left", pifacecad_lcd_move_left);
	NODE_SET_METHOD(exports, "lcd_move_right", pifacecad_lcd_move_right);
	NODE_SET_METHOD(exports, "lcd_left_to_right", pifacecad_lcd_left_to_right);
	NODE_SET_METHOD(exports, "lcd_right_to_left", pifacecad_lcd_right_to_left);
	NODE_SET_METHOD(exports, "lcd_autoscroll", pifacecad_lcd_autoscroll);
	NODE_SET_METHOD(exports, "lcd_autoscroll_on", pifacecad_lcd_autoscroll_on);
	NODE_SET_METHOD(exports, "lcd_autoscroll_off", pifacecad_lcd_autoscroll_off);
	NODE_SET_METHOD(exports, "lcd_write_custom_bitmap", pifacecad_lcd_write_custom_bitmap);
	NODE_SET_METHOD(exports, "lcd_store_custom_bitmap", pifacecad_lcd_store_custom_bitmap);
	NODE_SET_METHOD(exports, "lcd_send_command", pifacecad_lcd_send_command);
	NODE_SET_METHOD(exports, "lcd_send_data", pifacecad_lcd_send_data);
	NODE_SET_METHOD(exports, "lcd_send_byte", pifacecad_lcd_send_byte);
	NODE_SET_METHOD(exports, "lcd_set_rs", pifacecad_lcd_set_rs);
	NODE_SET_METHOD(exports, "lcd_set_rw", pifacecad_lcd_set_rw);
	NODE_SET_METHOD(exports, "lcd_set_enable", pifacecad_lcd_set_enable);
	NODE_SET_METHOD(exports, "lcd_set_backlight", pifacecad_lcd_set_backlight);
	NODE_SET_METHOD(exports, "lcd_pulse_enable", pifacecad_lcd_pulse_enable);
	NODE_SET_METHOD(exports, "colrow2address", colrow2address);
	NODE_SET_METHOD(exports, "address2col", address2col);

}

NODE_MODULE(addon, Init);
