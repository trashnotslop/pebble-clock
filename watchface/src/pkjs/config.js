module.exports = [
  {
    type: "heading",
    defaultValue: "App Configuration",
  },
  {
    type: "select",
    messageKey: "digit",
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
  {
    type: "toggle",
    appKey: "backlight",
    label: "Keep backlight on?",
    defaultValue: true,
  },
  {
    type: "submit",
    defaultValue: "Save Settings",
  },
];
