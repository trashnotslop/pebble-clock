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
            label: "DEBUG",
            value: "0",
          },
          {
            label: "Hours 1",
            value: "1",
          },
          {
            label: "Hours 2",
            value: "2",
          },
          {
            label: "Minutes 1",
            value: "3",
          },
          {
            label: "Minutes 2",
            value: "4",
          },
          {
            label: "Seconds 1",
            value: "5",
          },
          {
            label: "Seconds 2",
            value: "6",
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
