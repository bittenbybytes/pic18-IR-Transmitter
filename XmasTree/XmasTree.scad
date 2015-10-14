thickness_top = 7;
thickness_stem = thickness_top - 2;

depth_cutout = 2.5;
coutout_h = depth_cutout+1;


difference(){
    union(){
        translate([-20,0,0])
        {
            cube([40,35,thickness_stem]);
        }

        translate([-20 +20,45,0])
        {
            rotate([0,0,90])
            {
                cylinder(thickness_top,50,40,$fn=3);
            }
        }

        translate([-20 +20,45+30,0])
        {
            rotate([0,0,90])
            {
                cylinder(thickness_top,40,30,$fn=3);
            }
        }

        translate([-20 +20,45+30+25,0])
        {
            rotate([0,0,90])
            {
                cylinder(thickness_top,30,20,$fn=3);
            }
        }
    }
    union(){
        
        translate([20,35,-1]){
            cylinder(h = 8, r = 3);
        }
        
        translate([-22,32,-1]){
            cylinder(h = 8, r = 3);
        }
        
        translate([-5,50,-1]){
            cylinder(h = 8, r = 3);
        }
        
        translate([-12,70,-1]){
            cylinder(h = 8, r = 3);
        }
        
        translate([7,80,-1]){
            cylinder(h = 8, r = 3);
        }
        
        translate([0,105,-1]){
            cylinder(h = 8, r = 3);
        }
        
        translate([-15,3,-1])
        {
            cube([30,25,coutout_h]);
        }
        
        translate([-5,3,-1])
        {
            cube([10,100,coutout_h-1]);
        }
        
        translate([-21,10,-1])
        {
            cube([12,8,coutout_h+1]);
        }
        
        translate([-20 +20,45,-1])
        {
            rotate([0,0,90])
            {
                cylinder(coutout_h-1,35,35,$fn=3);
            }
        }
        
        translate([-20 +20,45+30,-1])
        {
            rotate([0,0,90])
            {
                cylinder(coutout_h-1,25,25,$fn=3);
            }
        }
        
        translate([-20 +20,45+30+25,-1])
        {
            rotate([0,0,90])
            {
                cylinder(coutout_h-1,15,15,$fn=3);
            }
        }
    }
}
