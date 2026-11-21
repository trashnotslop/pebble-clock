module.exports = [
  {
    type: "heading",
    defaultValue: "App Configuration",
  },
  {
    type: "text",
    defaultValue: "Here is some introductory text.",
  },
  {
    type: "section",
    items: [
      {
        type: "heading",
        defaultValue: "Colors",
      },
      {
        type: "color",
        messageKey: "BackgroundColor",
        defaultValue: "0x000000",
        label: "Background Color",
      },
      {
        type: "color",
        messageKey: "ForegroundColor",
        defaultValue: "0xFFFFFF",
        label: "Foreground Color",
      },
    ],
  },
  {
    type: "section",
    items: [
      {
        type: "heading",
        defaultValue: "More Settings",
      },
      {
        type: "select",
        messageKey: "Digit",
        defaultValue: "0",
        options: [
          {
            label: "H1",
            value: "0",
          },
          {
            label: "H2",
            value: "1",
          },
          {
            label: "M1",
            value: "2",
          },
          {
            label: "M2",
            value: "3",
          },
          {
            label: "S1",
            value: "4",
          },
          {
            label: "S2",
            value: "5",
          },
        ],
      },
    ],
  },
  {
    type: "submit",
    defaultValue: "Save Settings",
  },
];
