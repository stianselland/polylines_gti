#include "ruby.h"

static void decode_polyline(VALUE points, VALUE polylines)
{
  
  VALUE polylines_str = StringValue(polylines);
  char *polylines_ptr = RSTRING_PTR(polylines_str);
  int len = RSTRING_LEN(polylines_str);
  int index = 0;
  int lat = 0, lng = 0;
  
  while(index < len) {
    
    int b, shift = 0, result = 0;
    
    do{
      b = polylines_ptr[index++] - 63;
      result |= (b & 0x1f) << shift;
      shift += 5;
    } while (b >= 0x20);
    int dlat = ((result & 1) != 0 ? ~(result >> 1) : (result >> 1));
    lat += dlat;
        
    shift = 0;
    result = 0;
    
    do {
      b = polylines_ptr[index++] - 63;
      result |= (b & 0x1f) << shift;
      shift += 5;
    } while (b >= 0x20);
    int dlng = ((result & 1) != 0 ? ~(result >> 1) : (result >> 1));
    lng += dlng;
    
    VALUE point = rb_ary_new();
    rb_ary_push(point, rb_float_new((double)lat/1E5));
    rb_ary_push(point, rb_float_new((double)lng/1E5));
    rb_ary_push(points, point);
  }  
}

static VALUE t_init(VALUE self)
{
  VALUE points;
  
  points = rb_ary_new();
  rb_iv_set(self, "@points", points);
  return self;
}

static VALUE t_decode(VALUE self, VALUE polylines)
{
  VALUE points;
  
  points = rb_iv_get(self, "@points");
  decode_polyline(points, polylines);  
  return points;
}

VALUE cPolyline;

void Init_polylines_gti()
{
  cPolyline = rb_define_class("PolylinesGti", rb_cObject);
  rb_define_method(cPolyline, "initialize", t_init, 0);
  rb_define_method(cPolyline, "decode", t_decode, 1);
}