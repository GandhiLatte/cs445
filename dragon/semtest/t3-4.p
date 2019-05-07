(* ERROR: mismatched type for index variable in FOR loops *)
program main( input, output );
  var a: integer;
  var x: real;
begin
  for 1 to 5 do
    a := a + 1.9
end.

