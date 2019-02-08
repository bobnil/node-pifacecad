{
  "targets": [{
    "target_name": "pifacecad",
    "sources": ["src/piface.cc"],
    "include_dirs": [
      "<!(node -e \"require('nan')\")",
      "./libpifacecad/src/"
    ],
    "link_settings": {
      "libraries": [
        "../libpifacecad/libpifacecad.a",
        "../libmcp23s17/libmcp23s17.a"
      ]
    },
    "cflags": ["-std=c++11"]
  }]
}
