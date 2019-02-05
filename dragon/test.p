program main(input, output);
    (* this is a comment *)
    var a,b: integer;
    var x,y,z: real;

    function foo(b:integer) : integer;
        var x: real;
        procedure bar(b: real);
        begin
            z := 2.718 {very illegal}
        end;
    begin
        x := 3.14 { illegal nonlocal update}
        bar(1.1);
        foo := 2*b
    end;

    { this is also a comment }
    procedure boo( p: integer; q: real );
        var a: real;
        var z: integer;
    begin
         writeln( p + 13);
    end;

    begin
        boo( 13, 3.14)
    end.